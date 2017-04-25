//////////////////////////////////////////////
//  Hax World			            //
//  --------------------------------------  //
//  This is the menu source for Hax World,  //
//  What it does:			    //
//  Displays the main menu		    //
//					    //
//  Coded by Ben Weidenhofer, under the     //
//  GPL license,  bla bla bla open source!  //
//////////////////////////////////////////////

#include "define.h"

SDL_Surface* background = NULL;
SDL_Surface* spritechar = NULL; // client's character sprite

void clean_up() {
	// Free surfaces
	SDL_FreeSurface(background);
	SDL_FreeSurface(spritechar);

	SDL_Quit();
}

SDL_Surface *load_image(std::string filename) { 

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

	return optimizedImage; 
} 
