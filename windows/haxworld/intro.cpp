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
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "settings.h"
#include <string> 

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
		ERROR_NUM = ERROR_NUM + 1;
		printf("\nError: could not load resource image: %s. Exiting now!\n",filename.c_str());
		clean_up();	
	}

	return optimizedImage; 
} 

int main(int argc, char* args[]) { 

	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) 
	{ 
		return 1; 
	} 
	
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_FULLSCREEN); 
	if(screen == NULL) 
	{ 
		ERROR_NUM = ERROR_NUM + 1;
		printf("\nError: Could not set resolution of %i x %i with %i BPP.\nExiting now!\n",SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP); 
		return 1; 
	} 
	
	//Initialize SDL_mixer 
	if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{ 
		ERROR_NUM = ERROR_NUM + 1;
		clean_up();
	} 	 
	
	SDL_WM_SetCaption("Hax World", NULL); 

	// Load the images 
	intro = load_image("images/intro.bmp"); 
	loading = load_image("images/loading.bmp"); 

	if(intro == NULL) {
		ERROR_NUM = ERROR_NUM + 1;
		printf("\nError: could not load resource image: images/intro.bmp. Exiting now!\n");
		clean_up();	
	} else {
	}

	if(loading == NULL) {
		ERROR_NUM = ERROR_NUM + 1;
		printf("\nError: could not load resource image: images/loading.bmp. Exiting now!\n");
		clean_up();
 	} else { 
	}

	bool quit = false;
	
        apply_loadscreen();

	// update the screen
	if(SDL_Flip(screen) == -1) {
		return 1;
	}

	music = Mix_LoadMUS("data/music/toneage.wav");
	//If there was a problem loading the music 
	if(music == NULL) 
	{ 
		ERROR_NUM = ERROR_NUM + 1;
		printf("\nError: data/music/toneage.wav. Exiting now!\n");
		clean_up();
	} 

	menu_music = Mix_LoadWAV("data/music/toneage.wav");
	if(menu_music == NULL)
	{ 
		ERROR_NUM = ERROR_NUM + 1;
		printf("\nError: data/music/toneage.wav. Exiting now!\n");
		clean_up();
	} 

	while(quit == false) {
		while(SDL_PollEvent(&event)) {
			//If 1 was pressed 
			if(Mix_PlayChannel(-1, menu_music, 0) == -1) 
			{ 
				ERROR_NUM = ERROR_NUM + 1;
				printf("\nError: data/music/toneage.wav. Exiting now!\n");
				clean_up();
				return 1; 
			} 

			// if user X'ed out of the window
			if(event.type == SDL_QUIT)
			{
				//quit
				quit = true;
				if(quit == true)
				{
					printf("\nUser has exited manually.\n");
					clean_up();
					return 0; 
				}
			}
		}
	}

	clean_up();
	return 0; 
}