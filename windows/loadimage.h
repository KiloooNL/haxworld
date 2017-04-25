#include "define.h"
#include <stdlib.h>
#include <math.h>

/* COLOR KEYS AND MAIN SURFACES */
static int color_key; // this is for the transparant images
static SDL_Surface *screen = NULL; // SCREEN SURFACE - DO NOT EDIT!
static SDL_Surface *background = NULL; // BACKGROUND SURFACE - DO NOT EDIT
static SDL_Surface *sprite = NULL;		// PLAYER SPRITE
static SDL_Surface **base_sprites = NULL;

// ON CALL SDL_QUIT()
static SDL_Surface *quitter = NULL;

static SDL_Surface *load_image(std::string filename) { 

	SDL_Surface* loadedImage = NULL; 
	SDL_Surface* optimizedImage = NULL; 

	loadedImage = SDL_LoadBMP(filename.c_str()); 

	//If nothing went wrong in loading the image 
	if(loadedImage != NULL) { 
		optimizedImage = SDL_DisplayFormat(loadedImage); 
		SDL_FreeSurface(loadedImage); 

		if(optimizedImage != NULL) { 
			// Map the color key 
			// 00FFFF = sort of like... really light blue.
			Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF); 
			SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey); 
		} 
	} 
	else {
		printf("\nError: could not load resource image: %s. Exiting now!\n",filename.c_str());
		SDL_Quit();	
	}

	return optimizedImage; 
} 