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
		error();	
	}

	return optimizedImage; 
} 

int main(int argc, char* args[]) { 
	start_SDL();
	setup_screen();	
	
	//Initialize SDL_mixer 
	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1) { 
		error();
	} 	 
	
	SDL_WM_SetCaption("Hax World", NULL); 

	// Load the images 
	intro = load_image("images/intro.bmp"); 
	loading = load_image("images/loading.bmp"); 

	if(intro && loading == NULL) {
		error();
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
	if(music == NULL)  { 
		error();
	} 

	menu_music = Mix_LoadWAV("data/music/toneage.wav");
	if(menu_music == NULL) { 
		error();
	} 

	while(quit == false) {
		while(SDL_PollEvent(&event)) {
			if(Mix_PlayChannel(-1, menu_music, 0) == -1) { 
				error();
				return 1; 

			if(music == NULL)  { 
				menu_music = Mix_LoadWAV("data/music/toneage.wav");
				} 
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
