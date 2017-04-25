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

SDL_Surface* intro = NULL;   // intro
SDL_Surface* screen = NULL;  // screen
SDL_Surface* loading = NULL; // when loading

SDL_Event event;

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination) { 

	SDL_Rect offset; 

	offset.x = x; 
	offset.y = y;
	
	SDL_BlitSurface(source, NULL, destination, &offset); 
} 

void apply_loadscreen() {

	// show images on screen
	apply_surface(0, 0, intro, screen); 
	apply_surface(111, 230, loading, screen);
}

/***************************************************************\
*			SDL_Mixer stuff                         *
\***************************************************************/
//The music that will be played 
Mix_Music *music = NULL; 

//The sound effects that will be used 
Mix_Chunk *menu_music = NULL;
/***************************************************************\
\***************************************************************/



// Clean Up
void clean_up() {
	// Free Surfaces
	SDL_FreeSurface(intro);
	SDL_FreeSurface(loading);
	SDL_FreeSurface(screen);

	//Free the sound effects 
	Mix_FreeChunk(menu_music);  
	Mix_FreeMusic(music); 

	//Quit SDL_mixer 
	Mix_CloseAudio(); 

	printf("\nCleaning up...");
	printf("\nCleaned up successfully\n");
	SDL_Quit();		// quit
	printf("\nErrors: %i \n",ERROR_NUM);
}