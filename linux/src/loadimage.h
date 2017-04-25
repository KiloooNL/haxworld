#include "define.h"

// Loads an image
static int color_key; // this is for the transparant images
static SDL_Surface* screen = NULL;

/* MENU IMAGES & BUTTONS ARE DEFINED HERE */
static SDL_Surface* intro = NULL;   // intro
static SDL_Surface* loading = NULL; // when loading
static SDL_Surface* quitter = NULL; // picture for exit
static SDL_Surface* background = NULL;
static SDL_Surface* spritechar = NULL; // client's character sprite
// buttons
static SDL_Surface* sp = NULL;
static SDL_Surface* mp = NULL;
static SDL_Surface* option = NULL;
static SDL_Surface* about = NULL;
static SDL_Surface* ex = NULL;

/* GAME IMAGES ARE DEFINED HERE */
static SDL_Surface* sprite = NULL;

static SDL_Surface *load_image(std::string filename) { 

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
		//clean_up();	
	}

	return optimizedImage; 
} 

static void load_MenuImages() {
	intro = load_image("images/intro.bmp"); 
	loading = load_image("images/loading.bmp"); 
	quitter = load_image("images/quitter.bmp");
	background = load_image("images/menu.bmp");
	sp = load_image("images/buttons/sp.bmp");
	mp = load_image("images/buttons/mp.bmp");
	option = load_image("images/buttons/option.bmp");
	about = load_image("images/buttons/about.bmp");
	ex = load_image("images/buttons/exit.bmp");
	spritechar = load_image("images/sprites/stickman/stickman.bmp");
}
