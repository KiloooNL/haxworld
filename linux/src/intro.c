//////////////////////////////////////////////
//  Hax World			            //
//  --------------------------------------  //
//  This is the intro source for Hax World, //
//  What it does:			    //
//  Displays the introduction animation on  // 
//  the screen then jumps to the main menu  //
//					    //
//  Coded by Ben Weidenhofer, under the     //
//  GPL license,  bla bla bla open source!  //
//////////////////////////////////////////////

#include "SDL/SDL.h" 
#include <string> 

//The attributes of the screen 
const int SCREEN_WIDTH = 640; 
const int SCREEN_HEIGHT = 480; 
const int SCREEN_BPP = 32;

SDL_Surface* intro = NULL;   // intro
SDL_Surface* screen = NULL;  // screen
SDL_Surface* loading = NULL; // when loading
SDL_Event event;

// Clean Up
void clean_up() {
	SDL_FreeSurface(intro); // free surface, release memory so there's no leaks
	SDL_FreeSurface(loading);

	SDL_Quit();		// quit
}


SDL_Surface *load_image(std::string filename) { 

	SDL_Surface* loadedImage = NULL; 
	SDL_Surface* optimizedImage = NULL; 

	loadedImage = SDL_LoadBMP(filename.c_str()); 

	// If nothing went wrong in loading the image 
	if( loadedImage != NULL ) { 
		optimizedImage = SDL_DisplayFormat(loadedImage); 
		SDL_FreeSurface(loadedImage); 
	} 
	else {
		printf("\nError: could not load resource image: %s. Exiting now!\n",filename.c_str());
		clean_up();	
	}

	return optimizedImage; 
} 

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination) { 

	SDL_Rect offset; 

	offset.x = x; 
	offset.y = y;
	
	SDL_BlitSurface(source, NULL, destination, &offset); 
} 

int main( int argc, char* args[] ) { 

	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) 
	{ 
		return 1; 
	} 
	
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE); 
	if(screen == NULL) 
	{ 
		printf("\nError: Could not set resolution of %i x %i with %i BPP.\nExiting now!\n",SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP); 
		return 1; 
	} 
	 
	SDL_WM_SetCaption("Hax World", NULL); 

	// Load the images 
	intro = load_image("images/intro.bmp"); 
	loading = load_image("images/loading.bmp"); 

	if(intro == NULL) {
		printf("\nError: could not load resource image: images/intro.bmp. Exiting now!\n");
		clean_up();	
	} else if(loading == NULL) {
		printf("\nError: could not load resource image: images/loading.bmp. Exiting now!\n");
		clean_up();
 	} else { 

	}

	bool quit = false;
	
	// show images on screen
	apply_surface(0, 0, intro, screen); 
	apply_surface(111, 230, loading, screen);

	// update the screen
	if(SDL_Flip(screen) == -1) {
		return 1;
	}

	while(quit==false) {
		while(SDL_PollEvent(&event)) {
			
			// if user X'ed out of the window
			if(event.type == SDL_QUIT)
			{
				//quit
				quit = true;
				if(quit == true)
				{
					printf("\nUser has exited manually.\n");
					printf("\nCleaning up...\n");
					clean_up();
					printf("\nCleaned up successfully\n");
					return 0; 
				}
			}
		}
	}

	clean_up();
	return 0; 
}
