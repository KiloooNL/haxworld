//////////////////////////////////////////////
//  Hax World			            //
//  --------------------------------------  //
//  This is the intro source for Hax World, //
//  What it does:			    //
//  Displays the introduction animation on  // 
//  the screen then jumps to the main menu  //
//////////////////////////////////////////////

#include "audio.c"
#include "define.h"
#include "game.c"
#include "config.c"
#include "video.c"
#include "version.c"

bool quit = false;

SDL_Surface* options_bg = NULL; // options menu
static int cleaned;
static SDL_Event event;

/* 
NOTE:
        HaxWorld will compile though it will not be able to exit unless forced
        if you try to free a surface that is NULL!
*/ 

static void clean_up_menu () {
	cleaned = 0;
	SDL_FreeSurface(background);
	SDL_FreeSurface(sp);
	SDL_FreeSurface(mp);
	SDL_FreeSurface(option);
	SDL_FreeSurface(about);
	SDL_FreeSurface(ex);
	SDL_FreeSurface(spritechar);
	SDL_Flip(screen);
}

extern void clean_up() {
	printf("\nCleaning up...\n");
	printf("Freeing surfaces...\n");
	SDL_FreeSurface(background);
	SDL_FreeSurface(sp);
	SDL_FreeSurface(mp);
	SDL_FreeSurface(option);
	SDL_FreeSurface(about);
	SDL_FreeSurface(ex);
	SDL_FreeSurface(spritechar);

	printf("Showing exit screen...\n");
	apply_surface(0, 0, quitter, screen);
	SDL_Flip(screen);
	SDL_Delay(1000);
	SDL_FreeSurface(quitter);
	SDL_Delay(1000);
	printf("Cleaned up successfully!\n");

	SDL_Quit();
}

int main(int argc, char* args[]) { 


	// Ok... so basically what I want to do here is code a 'version.c' file that detects the games current build version,
	// then display it here... but i'm not sure how to do that so far :( so for now just put "version/revision xx"

	// WELCOME MESSAGE
	printf("\nWelcome to HaxWorld.");
	// REVISION
	version();
	printf("\n");

	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) { 
		return 1; 
	} 
	SDL_WM_SetCaption("Hax World", NULL); 
	
	config(); // loads the config

	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE); 
	if(screen == NULL) { 
		printf("\nCould not set resolution of: %ix%i \nError details: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		return 1; 
	} 
 
	menu_music(); // Initialize & play menu music
	load_MenuImages();
	
	// show images on screen
	apply_surface(0, 0, intro, screen); 
	apply_surface(111, 330, loading, screen);
	SDL_FreeSurface(intro);
	SDL_FreeSurface(loading);	
	SDL_Flip(screen);
	SDL_Delay(1000);

	apply_surface(0, 0, background, screen);

	// Menu items
	apply_surface(207, 129, sp, screen);
	apply_surface(207, 189, mp, screen);
	apply_surface(207, 249, option, screen);
	apply_surface(207, 309, about, screen);
	apply_surface(207, 369, ex, screen);
	apply_surface(160, 10, spritechar, screen);
	SDL_Flip(screen);

	while(quit==false) {
		while(SDL_PollEvent(&event)) {
			// if user X'ed out of the window
			if(event.type == SDL_QUIT) {
				//while(Mix_Playing(channel) != 0);
				Mix_FreeChunk(sound);
				Mix_CloseAudio();
				//quit
				quit = true;
				printf("\nUser has exited manually.\n");
			}
			//If a key was pressed 
			else if(event.type == SDL_KEYDOWN) {
				switch(event.key.keysym.sym) { 
					case SDLK_ESCAPE: // esc
						quit = true;
						break;
					case SDLK_RETURN: // enter
						if(cleaned == 0) {
							clean_up_menu();
						
							background = load_image("images/background.bmp");
							apply_surface(0, 0, background, screen);
							SDL_Flip(screen);
							single_player();
						} else {
							single_player();
						}
						break;
					
					case SDLK_UP:     // up
						printf("Directional keys not functionable on menu as of R23");
						/* not available yet
						sp = load_image("images/buttons/sp_select.bmp");
						mp = load_image("images/buttons/mp.bmp");
						apply_surface(207, 189, mp, screen);
						apply_surface(207, 129, sp, screen);
						SDL_Flip(screen); */
						break; 
					case SDLK_DOWN:   // down
						printf("Directional keys not functionable on menu as of R23");
						/* not available yet
						mp = load_image("images/buttons/mp_select.bmp");
						sp = load_image("images/buttons/sp.bmp");

						apply_surface(207, 189, mp, screen);
						apply_surface(207, 129, sp, screen);
						SDL_Flip(screen); */
						break; 
				}
			}
		}
	}

	clean_up();
	return 0; 
}
