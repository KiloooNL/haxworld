//////////////////////////////////////////////
//  Hax World			            //
//  --------------------------------------  //
//  This is the menu source for Hax World,  //
//  What it does:			    //
//  Displays the main menu		    //
//////////////////////////////////////////////

#include "define.h"

static SDL_Surface* background = NULL;
static SDL_Surface* spritechar = NULL; // client's character sprite
static SDL_Surface* screen = NULL;

void clean_up() {
	// Free surfaces
	SDL_FreeSurface(background);
	SDL_FreeSurface(spritechar);

	SDL_Quit();
}

SDL_Surface *load_image(std::string filename) { 

	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE); 
	if(screen == NULL) { 
		printf("Error details: %s\n", SDL_GetError()); 
	} 

	SDL_Surface* loadedImage = NULL; 
	SDL_Surface* optimizedImage = NULL; 

	loadedImage = SDL_LoadBMP(filename.c_str()); 

	//If nothing went wrong in loading the image 
	if(loadedImage != NULL) { 
		optimizedImage = SDL_DisplayFormat(loadedImage); 
		SDL_FreeSurface(loadedImage); 

		if(optimizedImage != NULL) { 
			//Map the color key 
			// 00FFFF = sort of like... really light blue.
			Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF); 
			SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey); 
		} 
	} 
	else {
		printf("\nError: could not load resource image: %s. Exiting now!\n",filename.c_str());
		clean_up();	
	}

	background = load_image("images/menu.bmp");
	apply_surface(0, 0, background, screen);

	SDL_Flip(screen);

	return optimizedImage; 
} 
