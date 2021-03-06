#include "PatchUtil.h"

#include "mwOffsets.h"
#include "MemoryUtil.h"
#include "Log.h"

#include "TES3Actor.h"
#include "TES3BodyPartManager.h"
#include "TES3DataHandler.h"
#include "TES3Game.h"
#include "TES3GameFile.h"
#include "TES3GameSetting.h"
#include "TES3Misc.h"
#include "TES3MobilePlayer.h"
#include "TES3Reference.h"
#include "TES3Script.h"
#include "TES3UIElement.h"
#include "TES3UIInventoryTile.h"
#include "TES3WorldController.h"

#include "NIFlipController.h"
#include "NILinesData.h"
#include "NIUVController.h"

#include "BitUtil.h"
#include "TES3Util.h"
#include "ScriptUtil.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "MWSEConfig.h"

namespace mwse {
	namespace patch {

		//
		// Patch: Enable
		//

		void PatchScriptOpEnable() {
			TES3::ScriptVariables* scriptVars = mwscript::getLocalScriptVariables();
			if (scriptVars) {
				scriptVars->unknown_0xC &= 0xFE;
			}
		}

		//
		// Patch: Disable
		//

		static bool PatchScriptOpDisable_ForceCollisionUpdate = false;

		void PatchScriptOpDisable() {
			TES3::ScriptVariables* scriptVars = mwscript::getLocalScriptVariables();
			if (scriptVars) {
				scriptVars->unknown_0xC |= 0x1;
			}

			// Determine if we need to force update collision.
			auto reference = mwscript::getScriptTargetReference();
			if (reference) {
				PatchScriptOpDisable_ForceCollisionUpdate = !reference->getDisabled();
			}
			else {
				PatchScriptOpDisable_ForceCollisionUpdate = false;
			}
		}

		void* __fastcall PatchScriptOpDisableCollision(TES3::Reference* reference) {
			// Force update collision.
			if (PatchScriptOpDisable_ForceCollisionUpdate) {
				TES3::DataHandler::get()->updateCollisionGroupsForActiveCells();
			}

			// Return overwritten code.
			return &reference->baseObject;
		}

		//
		// Patch: Unify athletics training.
		//

		void PatchUnifyAthleticsTraining() {
			TES3::WorldController* worldController = TES3::WorldController::get();
			TES3::MobilePlayer* mobilePlayer = worldController->getMobilePlayer();

			TES3::Skill* athletics = &TES3::DataHandler::get()->nonDynamicData->skills[TES3::SkillID::Athletics];

			// If we're running, use the first progress.
			if (mobilePlayer->movementFlags & TES3::ActorMovement::Running) {
				mobilePlayer->exerciseSkill(TES3::SkillID::Athletics, athletics->progressActions[0] * worldController->deltaTime);
			}

			// If we're swimming, use the second progress.
			if (mobilePlayer->movementFlags & TES3::ActorMovement::Swimming) {
				mobilePlayer->exerciseSkill(TES3::SkillID::Athletics, athletics->progressActions[1] * worldController->deltaTime);
			}
		}

		//
		// Patch: Unify sneak training.
		//

		void PatchUnifySneakTraining() {
			TES3::NonDynamicData* nonDynamicData = TES3::DataHandler::get()->nonDynamicData;

			// Decrement sneak use delay counter.
			*reinterpret_cast<float*>(0x7D16E0) = *reinterpret_cast<float*>(0x7D16E0) - nonDynamicData->GMSTs[TES3::GMST::fSneakUseDelay]->value.asFloat;

			// Excercise sneak.
			TES3::WorldController::get()->getMobilePlayer()->exerciseSkill(TES3::SkillID::Sneak, nonDynamicData->skills[TES3::SkillID::Sneak].progressActions[0]);
		}

		//
		// Patch: Fix crash with paper doll equipping/unequipping.
		//
		// In this patch, the tile associated with the stack may have been deleted, but the property to the TES3::ItemData 
		// remains. If the memory is reallocated it will fill with garbage, and cause a crash. The tile property, however,
		// is properly deleted. So we look for that instead, and return its associated item data (which is the same value).
		//! TODO: Find out where it's being deleted, and also delete the right property.
		//

		TES3::UI::PropertyValue* __fastcall PatchPaperdollTooltipCrashFix(TES3::UI::Element* self, DWORD _UNUSUED_, TES3::UI::PropertyValue* propValue, TES3::UI::Property prop, TES3::UI::PropertyType propType, const TES3::UI::Element* element = nullptr, bool checkInherited = false) {
			auto tileProp = self->getProperty(TES3::UI::PropertyType::Pointer, *reinterpret_cast<TES3::UI::Property*>(0x7D3A70));
			auto tile = reinterpret_cast<TES3::UI::InventoryTile*>(tileProp.ptrValue);

			if (tile == nullptr) {
				propValue->ptrValue = nullptr;
			}
			else {
				propValue->ptrValue = tile->itemData;
			}

			return propValue;
		}

		//
		// Patch: Allow the game to correctly close when quit with a messagebox popup.
		//
		// The game holds up a TES3::UI messagebox and runs its own infinite loop waiting for a response
		// when a critical error has occurred. This does not respect the WorldController's stopGameLoop
		// flag, which is set when the user attempts to close the window.
		//
		// Here we check if that flag is set, and if it is, force a choice on the "no" dialogue option,
		// which stops the deadlock.
		//

		int __cdecl SafeQuitGetMessageChoice() {
			if (TES3::WorldController::get()->stopGameLoop) {
				log::getLog() << "[MWSE] Prevented rogue Morrowind.exe instance." << std::endl;
				*reinterpret_cast<int*>(0x7B88C0) = 1;
			}

			return *reinterpret_cast<int*>(0x7B88C0);
		}

		//
		// Patch: Optimize DontThreadLoad, prevent multi-thread loading from lua.
		//
		// Every time the game wants to load, it checks the ini file from disk for the DontThreadLoad value.
		// This patch caches the value so it only needs to be read once.
		//
		// Additionally, this provides a way to suppress thread loading from lua, if it is causing an issue in
		// a script (namely, a lua state deadlock).
		//

		UINT WINAPI	OverrideDontThreadLoad(LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault, LPCSTR lpFileName) {
			return TES3::DataHandler::suppressThreadLoad || TES3::DataHandler::dontThreadLoad;
		}

		//
		// Patch: Make Morrowind believe that it is always the front window in the main gameplay loop block.
		//

		HWND __stdcall PatchGetMorrowindMainWindow() {
			return TES3::WorldController::get()->Win32_hWndParent;
		}

		//
		// Patch: Optimize access to global variables. Access them in a hashmap instead of linear searching.
		//

		auto __fastcall DataHandlerCreateGlobalsContainer(void* garbage) {
			mwse::tes3::_delete(garbage);
			return new TES3::GlobalHashContainer();
		}

		const auto TES3_WorldController_InitGlobals = reinterpret_cast<void (__thiscall*)(TES3::WorldController*)>(0x40E920);
		void __fastcall WorldControllerInitGlobals(TES3::WorldController* worldController) {
			// Call original code.
			TES3_WorldController_InitGlobals(worldController);

			// New variables.
			auto globals = TES3::DataHandler::get()->nonDynamicData->globals;
			globals->addVariableCacheOnly(worldController->gvarGameHour);
			globals->addVariableCacheOnly(worldController->gvarYear);
			globals->addVariableCacheOnly(worldController->gvarMonth);
			globals->addVariableCacheOnly(worldController->gvarDay);
			globals->addVariableCacheOnly(worldController->gvarDaysPassed);
			globals->addVariableCacheOnly(worldController->gvarTimescale);
			globals->addVariableCacheOnly(worldController->gvarCharGenState);
			globals->addVariableCacheOnly(worldController->gvarMonthsToRespawn);
		}

		//
		// Install all the patches.
		//

		void installPatches() {
			// Patch: Enable/Disable.
			genCallUnprotected(0x508FEB, reinterpret_cast<DWORD>(PatchScriptOpEnable), 0x9);
			genCallUnprotected(0x5090DB, reinterpret_cast<DWORD>(PatchScriptOpDisable), 0x9);
			genCallUnprotected(0x50912F, reinterpret_cast<DWORD>(PatchScriptOpDisableCollision));

			// Patch: Unify athletics and sneak training.
			genCallUnprotected(0x569EE7, reinterpret_cast<DWORD>(PatchUnifyAthleticsTraining), 0xC6);
			genCallUnprotected(0x5683D0, reinterpret_cast<DWORD>(PatchUnifySneakTraining), 0x65);

			// Patch: Crash fix for help text for paperdolls.
			genCallEnforced(0x5CDFD0, 0x581440, reinterpret_cast<DWORD>(PatchPaperdollTooltipCrashFix));

			// Patch: Optimize GetDeadCount and associated dialogue filtering/logic.
			auto killCounter_increment = &TES3::KillCounter::incrementMobile;
			genCallEnforced(0x523D73, 0x55D820, *reinterpret_cast<DWORD*>(&killCounter_increment));
			auto killCounter_getCount = &TES3::KillCounter::getKillCount;
			genCallEnforced(0x4B0B2E, 0x55D900, *reinterpret_cast<DWORD*>(&killCounter_getCount));
			genCallEnforced(0x50AC85, 0x55D900, *reinterpret_cast<DWORD*>(&killCounter_getCount));
			genCallEnforced(0x50ACAB, 0x55D900, *reinterpret_cast<DWORD*>(&killCounter_getCount));
			genCallEnforced(0x745FF0, 0x55D900, *reinterpret_cast<DWORD*>(&killCounter_getCount));
#if MWSE_CUSTOM_KILLCOUNTER
			auto killCounter_ctor = &TES3::KillCounter::ctor;
			genCallEnforced(0x40DE9B, 0x55D750, *reinterpret_cast<DWORD*>(&killCounter_ctor));
			auto killCounter_dtor = &TES3::KillCounter::dtor;
			genCallEnforced(0x40E049, 0x55D7D0, *reinterpret_cast<DWORD*>(&killCounter_dtor));
			auto killCounter_clear = &TES3::KillCounter::clear;
			genCallEnforced(0x4C6F76, 0x55DBD0, *reinterpret_cast<DWORD*>(&killCounter_clear));
			auto killCounter_load = &TES3::KillCounter::load;
			genCallEnforced(0x4C076C, 0x55DA90, *reinterpret_cast<DWORD*>(&killCounter_load));
			auto killCounter_save = &TES3::KillCounter::save;
			genCallEnforced(0x4BCB7E, 0x55D950, *reinterpret_cast<DWORD*>(&killCounter_save));
#endif

			// Patch: Don't truncate hour when advancing time past midnight.
			// Also don't nudge time forward by small extra increments when resting.
			auto WorldController_tickClock = &TES3::WorldController::tickClock;
			genCallEnforced(0x41B857, 0x40FF50, *reinterpret_cast<DWORD*>(&WorldController_tickClock));
			auto WorldController_checkForDayWrapping = &TES3::WorldController::checkForDayWrapping;
			genCallEnforced(0x6350E9, 0x40FF50, *reinterpret_cast<DWORD*>(&WorldController_checkForDayWrapping));

			// Patch: Prevent error messageboxes from creating a rogue process.
			genCallEnforced(0x47731B, 0x5F2160, reinterpret_cast<DWORD>(SafeQuitGetMessageChoice));
			genCallEnforced(0x4779D9, 0x5F2160, reinterpret_cast<DWORD>(SafeQuitGetMessageChoice));
			genCallEnforced(0x477E6F, 0x5F2160, reinterpret_cast<DWORD>(SafeQuitGetMessageChoice));

			// Patch: Cache DontThreadLoad INI value and extend it with a suppression flag.
			TES3::DataHandler::dontThreadLoad = GetPrivateProfileIntA("General", "DontThreadLoad", 0, ".\\Morrowind.ini") != 0;
			genCallUnprotected(0x48539C, reinterpret_cast<DWORD>(OverrideDontThreadLoad), 0x6);
			genCallUnprotected(0x4869DB, reinterpret_cast<DWORD>(OverrideDontThreadLoad), 0x6);
			genCallUnprotected(0x48F489, reinterpret_cast<DWORD>(OverrideDontThreadLoad), 0x6);
			genCallUnprotected(0x4904D0, reinterpret_cast<DWORD>(OverrideDontThreadLoad), 0x6);

			// Patch: Fix NiLinesData binary loading.
			auto NiLinesData_loadBinary = &NI::LinesData::loadBinary;
			overrideVirtualTableEnforced(0x7501E0, offsetof(NI::Object_vTable, loadBinary), 0x6DA410, *reinterpret_cast<DWORD*>(&NiLinesData_loadBinary));

			// Patch: Try to catch bogus collisions.
			auto MobileObject_Collision_clone = &TES3::MobileObject::Collision::clone;
			genCallEnforced(0x537107, 0x405450, *reinterpret_cast<DWORD*>(&MobileObject_Collision_clone));
			genCallEnforced(0x55F7C4, 0x405450, *reinterpret_cast<DWORD*>(&MobileObject_Collision_clone));
			genCallEnforced(0x55F818, 0x405450, *reinterpret_cast<DWORD*>(&MobileObject_Collision_clone));

			// Patch: Fix up transparency.
			auto BodyPartManager_updateForReference = &TES3::BodyPartManager::updateForReference;
			genCallEnforced(0x46444C, 0x473EA0, *reinterpret_cast<DWORD*>(&BodyPartManager_updateForReference));
			genCallEnforced(0x4DA07C, 0x473EA0, *reinterpret_cast<DWORD*>(&BodyPartManager_updateForReference));

			// Patch: Decrease MO2 load times. Somehow...
			writeDoubleWordUnprotected(0x7462F4, reinterpret_cast<DWORD>(&_stat32));

			// Patch: Fix NiFlipController losing its affectedMap on clone.
			auto NiFlipController_clone = &NI::FlipController::copy;
			genCallEnforced(0x715D26, 0x715D40, *reinterpret_cast<DWORD*>(&NiFlipController_clone));

			// Patch: Fix NiUVController losing its texture set on clone.
			auto UVController_clone = &NI::UVController::copy;
			genCallEnforced(0x722317, 0x722330, *reinterpret_cast<DWORD*>(&UVController_clone));

			// Patch: Make globals less slow to access.
#if MWSE_CUSTOM_GLOBALS
			genCallEnforced(0x4B7D74, 0x47E1E0, reinterpret_cast<DWORD>(DataHandlerCreateGlobalsContainer));
			genCallEnforced(0x41A029, 0x40E920, reinterpret_cast<DWORD>(WorldControllerInitGlobals));
			genCallEnforced(0x4C6012, 0x40E920, reinterpret_cast<DWORD>(WorldControllerInitGlobals));
			genCallEnforced(0x5FB10F, 0x40E920, reinterpret_cast<DWORD>(WorldControllerInitGlobals));
			genCallEnforced(0x5FE91E, 0x40E920, reinterpret_cast<DWORD>(WorldControllerInitGlobals));
			auto GlobalHashContainer_addVariable = &TES3::GlobalHashContainer::addVariable;
			genCallEnforced(0x4BD8AF, 0x47E360, *reinterpret_cast<DWORD*>(&GlobalHashContainer_addVariable));
			genCallEnforced(0x4BD906, 0x47E360, *reinterpret_cast<DWORD*>(&GlobalHashContainer_addVariable));
			genCallEnforced(0x565E0B, 0x47E360, *reinterpret_cast<DWORD*>(&GlobalHashContainer_addVariable));
			genCallEnforced(0x565E9A, 0x47E360, *reinterpret_cast<DWORD*>(&GlobalHashContainer_addVariable));
			auto DataHandlerNonDynamicData_findGlobal = &TES3::NonDynamicData::findGlobalVariable;
			genCallEnforced(0x40C243, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x40E9AC, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x40EA4D, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x40EAEE, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x40EB8F, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x40EC30, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x40ECD1, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x40ED72, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x40EE13, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x49D893, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x4A4860, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x4AFB5C, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x4D85FE, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x4DF4F2, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x4F93B9, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x4FCCC3, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x4FDD53, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x4FEADD, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x500BE8, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x52D7B3, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x52D7C7, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x52D7DB, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x52D7F0, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x52D804, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x565D8E, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
			genCallEnforced(0x565E1C, 0x4BA820, *reinterpret_cast<DWORD*>(&DataHandlerNonDynamicData_findGlobal));
#endif
		}

		void installPostLuaPatches() {
			// Patch: The window is never out of focus.
			if (Configuration::RunInBackground) {
				writeByteUnprotected(0x416BC3 + 0x2 + 0x4, 1);
				genCallUnprotected(0x41AB7D, reinterpret_cast<DWORD>(PatchGetMorrowindMainWindow), 0x6);
			}
		}

		//
		// Create minidumps.
		//

		bool isDataSectionNeeded(const WCHAR* pModuleName) {
			// Check parameters.
			if (pModuleName == 0) {
				return false;
			}

			// Extract the module name.
			WCHAR szFileName[_MAX_FNAME] = L"";
			_wsplitpath(pModuleName, NULL, NULL, szFileName, NULL);

			// Compare the name with the list of known names and decide.
			if (_wcsicmp(szFileName, L"Morrowind") == 0) {
				return true;
			}
			else if (_wcsicmp(szFileName, L"ntdll") == 0)
			{
				return true;
			}
			else if (_wcsicmp(szFileName, L"MWSE") == 0)
			{
				return true;
			}

			// Complete.
			return false;
		}

		BOOL CALLBACK miniDumpCallback(PVOID pParam, const PMINIDUMP_CALLBACK_INPUT pInput, PMINIDUMP_CALLBACK_OUTPUT pOutput) {
			BOOL bRet = FALSE;

			// Check parameters 
			if (pInput == 0) {
				return FALSE;
			}
			if (pOutput == 0) {
				return FALSE;
			}

			// Process the callbacks 
			switch (pInput->CallbackType) {
			case IncludeModuleCallback:
			case IncludeThreadCallback:
			case ThreadCallback:
			case ThreadExCallback:
			{
				// Include the thread into the dump 
				bRet = TRUE;
			}
			break;

			case MemoryCallback:
			{
				// We do not include any information here -> return FALSE 
				bRet = FALSE;
			}
			break;

			case ModuleCallback:
			{
				// Does the module have ModuleReferencedByMemory flag set? 
				if (pOutput->ModuleWriteFlags & ModuleWriteDataSeg) {
					if (!isDataSectionNeeded(pInput->Module.FullPath)) {
						pOutput->ModuleWriteFlags &= (~ModuleWriteDataSeg);
					}
				}

				bRet = TRUE;
			}
			break;
			}

			return bRet;
		}

		void CreateMiniDump(EXCEPTION_POINTERS* pep) {
			log::getLog() << std::endl;
			log::getLog() << "Morrowind has crashed! To help improve game stability, send MWSE_Minidump.dmp and mwse.log to NullCascade@gmail.com or to NullCascade#1010 on Discord." << std::endl;

			// Display the memory usage in the log.
			PROCESS_MEMORY_COUNTERS_EX memCounter;
			GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&memCounter, sizeof(memCounter));
			log::getLog() << "Memory usage: " << memCounter.PrivateUsage << " bytes." << std::endl;

			// Try to print the lua stack trace.
			log::getLog() << "Lua traceback at time of crash:" << std::endl;
			mwse::lua::logStackTrace();

			// Open the file.
			HANDLE hFile = CreateFile("MWSE_MiniDump.dmp", GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

			if ((hFile != NULL) && (hFile != INVALID_HANDLE_VALUE)) {
				// Create the minidump.
				MINIDUMP_EXCEPTION_INFORMATION mdei;

				mdei.ThreadId = GetCurrentThreadId();
				mdei.ExceptionPointers = pep;
				mdei.ClientPointers = FALSE;

				MINIDUMP_CALLBACK_INFORMATION mci;

				mci.CallbackRoutine = (MINIDUMP_CALLBACK_ROUTINE)miniDumpCallback;
				mci.CallbackParam = 0;

				MINIDUMP_TYPE mdt = (MINIDUMP_TYPE)(MiniDumpWithDataSegs |
					MiniDumpWithHandleData |
					MiniDumpWithFullMemoryInfo |
					MiniDumpWithThreadInfo |
					MiniDumpWithUnloadedModules);

				BOOL rv = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, mdt, (pep != 0) ? &mdei : 0, 0, &mci);

				if (!rv) {
					log::getLog() << "MiniDump creation failed. Error: 0x" << std::hex << GetLastError() << std::endl;
				}
				else {
					log::getLog() << "MiniDump creation successful." << std::endl;
				}

				// Close the file
				CloseHandle(hFile);
			}
			else {
				log::getLog() << "MiniDump creation failed. Could not get file handle. Error: " << GetLastError() << std::endl;
			}
		}

		int __stdcall onWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
			__try {
				return reinterpret_cast<int(__stdcall *)(HINSTANCE, HINSTANCE, LPSTR, int)>(0x416E10)(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
			}
			__except (CreateMiniDump(GetExceptionInformation()), EXCEPTION_EXECUTE_HANDLER) {
				// Try to reset gamma.
				auto game = TES3::Game::get();
				if (game) {
					game->setGamma(1.0f);
				}

				return 0;
			}

		}

		bool installMiniDumpHook() {
#ifndef _DEBUG
			// Create our hook.
			return genCallEnforced(0x7279AD, 0x416E10, reinterpret_cast<DWORD>(onWinMain));
#else
			return true;
#endif
		}
	}
}
