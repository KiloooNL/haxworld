/////////////////////////////////////////////////////////////////////////
//  Hax World			                                       //
//  -------------------------------------- 			       //
//  This is the audio source code... but as for now it's really basic  //
//  I'm yet to add more as the game progresses                         //
/////////////////////////////////////////////////////////////////////////
#include "define.h"

// Don't edit these
static int audio_rate = 22050;
static Uint16 audio_format = AUDIO_S16SYS;
static int audio_channels = 2;
static int audio_buffers = 4096;
static int channel;

static Mix_Chunk *sound = NULL;

// Main Menu Music
static void menu_music() {
	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
		printf("\nUnable to initialize audio: %s\n", Mix_GetError());
		exit(1);
	}
 
	sound = Mix_LoadWAV("data/music/super-mario-intro.ogg");
	if(sound == NULL) {
		printf("\nUnable to load WAV file: %s\n", Mix_GetError());
	}
 
	channel = Mix_PlayChannel(-1, sound, 0);
	if(channel == -1) {
		fprintf(stderr, "\nUnable to play WAV file: %s\n", Mix_GetError());
	}
}
