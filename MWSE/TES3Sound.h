#pragma once

#include "TES3Defines.h"

#include "TES3Object.h"

namespace TES3 {
	namespace SoundPlayFlags {
		typedef int value_type;

		enum Flag {
			Loop = DSBPLAY_LOOPING,
		};
	}

	struct SoundBuffer {
		IDirectSoundBuffer * lpSoundBuffer;
		IDirectSound3DBuffer * lpSound3DBuffer;
		char fileHeader[16];
		short unknown_0x18;
		int unknown_0x1C;
		unsigned int flags;
		int waveSize;
		int unknown_0x28;
		unsigned char* wavHeader;
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		bool isVoiceover;
		short* rawAudio;
		int volume_related_0x48;
		unsigned char volume;
		int minDistance;
		int maxDistance;
	};
	static_assert(sizeof(SoundBuffer) == 0x58, "TES3::SoundBuffer failed size validation");

	struct Sound : BaseObject {
		char field_10;
		char id[32];
		char filename[32];
		unsigned char volume;
		unsigned char minDistance;
		unsigned char maxDistance;
		SoundBuffer* soundBuffer;

		//
		// Virtual table overrides.
		//

		char * getObjectID();

		//
		// Other related this-call functions.
		//

		bool play(int playbackFlags = 0, unsigned char volume = 250, float pitch = 1.0f, bool isNot3D = true);
		bool playRaw(int playbackFlags = 0, unsigned char volume = 250, float pitch = 1.0f, bool isNot3D = true);
		void stop();
		void setVolumeRaw(unsigned char volume);

		bool isPlaying();

		//
		// Custom functions.
		//

		const char* getFilename() const;

		float getVolume();
		void setVolume(float volume);

		std::string toJson() const;
		bool play_lua(sol::optional<sol::table> params);

	};
	static_assert(sizeof(Sound) == 0x58, "TES3::Sound failed size validation");
}

MWSE_SOL_CUSTOMIZED_PUSHER_DECLARE_TES3(TES3::Sound)
