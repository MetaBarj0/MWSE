#include "TES3StatisticLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Statistic.h"


namespace mwse {
	namespace lua {
		void bindTES3Statistic() {
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Statistic>("tes3statistic");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["base"] = sol::property(&TES3::Statistic::getBase, &TES3::Statistic::setBase);
				usertypeDefinition["current"] = sol::property(&TES3::Statistic::getCurrent, &TES3::Statistic::setCurrent_lua);
				usertypeDefinition["normalized"] = sol::property(&TES3::Statistic::getNormalized);
			}

			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::SkillStatistic>("tes3statisticSkill");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["base"] = sol::property(&TES3::SkillStatistic::getBase, &TES3::SkillStatistic::setBase);
				usertypeDefinition["current"] = sol::property(&TES3::SkillStatistic::getCurrent, &TES3::SkillStatistic::setCurrent_lua);
				usertypeDefinition["normalized"] = sol::property(&TES3::SkillStatistic::getNormalized);
				usertypeDefinition["type"] = &TES3::SkillStatistic::type;
			}
		}
	}
}


