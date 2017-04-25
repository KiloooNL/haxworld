#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <string> 

// The attributes of the screen 
const int SCREEN_WIDTH = 640; 
const int SCREEN_HEIGHT = 480; 
const int SCREEN_BPP = 32;
int ERROR_NUM = 0;

// Audio attributes
int channel;
int audio_rate = 22050;
Uint16 audio_format = AUDIO_S16SYS;
int audio_channels = 2;
int audio_buffers = 4096;

SDL_Surface* menubg = NULL;  // menu
SDL_Surface* intro = NULL;   // intro
SDL_Surface* screen = NULL;  // screen
SDL_Surface* loading = NULL; // when loading

SDL_Event event;

/***************************************************************\
*			SDL_Mixer stuff                         *
\***************************************************************/
//The music that will be played 
Mix_Music *music = NULL; 

//The sound effects that will be used 
Mix_Chunk *menu_music = NULL;
Mix_Chunk *sound = NULL;
/***************************************************************\
\***************************************************************/

/***************************************************************\
*	   Program functions here to save masses of code       *
\***************************************************************/

void clean_up() {
	// Free Surfaces
	SDL_FreeSurface(menubg);
	SDL_FreeSurface(intro);
	SDL_FreeSurface(loading);
	SDL_FreeSurface(screen);

	//Free the sound effects 
	Mix_FreeChunk(menu_music);
	Mix_FreeChunk(sound);  
	Mix_FreeMusic(music); 

	//Quit SDL_mixer 
	Mix_CloseAudio(); 

	printf("\nCleaning up...");
	printf("\nCleaned up successfully\n");
	SDL_Quit();		// quit
	printf("\nErrors: %i \n",ERROR_NUM);
}

void error() {
	ERROR_NUM = ERROR_NUM + 1;
	printf("Error details: %s\n", SDL_GetError());
	clean_up();
}

/***************************************************************\
\***************************************************************/

/***************************************************************\
*		Declerations for start of haxworld	       *
\***************************************************************/

void start_SDL() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
	}

}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination) { 

	SDL_Rect offset; 

	offset.x = x; 
	offset.y = y;
	
	SDL_BlitSurface(source, NULL, destination, &offset); 
} 

void setup_screen() {
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE); 
	if(screen == NULL)  { 
		error();
	} 
}

void apply_loadscreen() {
	apply_surface(0, 0, intro, screen); 
	apply_surface(111, 230, loading, screen);
}

/***************************************************************\
\***************************************************************/
