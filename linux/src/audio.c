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


// Used to initialize mixer
static void init_mixer() {
	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
		printf("\nUnable to initialize audio: %s\n", Mix_GetError());
		exit(1);
	}
}
// Used to play music
static void play_music() {	
    channel = Mix_PlayChannel(-1, sound, 0);
	if(channel == -1) {
		fprintf(stderr, "\nUnable to play file: %s\n", Mix_GetError());
	}
}
// Used to print error if sound file cannot be played/loaded
static void sound_error() {
       if(sound = NULL) {
                printf("\nUnable to load file: %s\n", Mix_GetError());
       }
}

// Main Menu Music
static void menu_music() {
    init_mixer(); // initialize mixer
	sound = Mix_LoadWAV("data/sounds/time/time_finish.wav");
	sound_error(); // print error if sound file cannot be played
}

// Level one music
static void level_one_music() {
    init_mixer(); // initialize mixer  
    sound = Mix_LoadWAV("data/music/levels/1.ogg");
	sound_error(); // print error if sound file cannot be played
}
