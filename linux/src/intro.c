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
#include "intro.h"
#include <string> 

SDL_Surface *load_image(std::string filename) { 

	SDL_Surface* loadedImage = NULL; 
	SDL_Surface* optimizedImage = NULL; 

	loadedImage = SDL_LoadBMP(filename.c_str()); 

	// If nothing went wrong in loading the image 
	if(loadedImage != NULL) { 
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
	
 
	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
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
	
	sound = Mix_LoadWAV("data/music/toneage.wav");
	if(sound == NULL) {
		error();
	}
 
	channel = Mix_PlayChannel(-1, sound, 0);
	if(channel == -1) {
			error();
	}

	while(quit == false) {
			if(channel == -1) {
				channel = Mix_PlayChannel(-1, sound, 0);		
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
	clean_up();
	return 0; 
}
