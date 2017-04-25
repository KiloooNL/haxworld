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
#include "loadimage.h"
#include "config.c"
#include "video.c"
#include "version.c"

bool quit = false;

SDL_Surface* intro = NULL;   // intro
SDL_Surface* options_bg = NULL; // options menu
SDL_Surface* loading = NULL; // when loading
SDL_Surface* screen = NULL;
SDL_Surface* quitter = NULL; // picture for exit B-)
SDL_Surface* background = NULL;
SDL_Surface* spritechar = NULL; // client's character sprite

// buttons
SDL_Surface* sp = NULL;
SDL_Surface* mp = NULL;
SDL_Surface* option = NULL;
SDL_Surface* about = NULL;
SDL_Surface* ex = NULL;

static SDL_Event event;

/* 
NOTE:
        HaxWorld will compile though it will not be able to exit unless forced
        if you try to free a surface that is NULL!
*/ 

static void clean_up_menu () {
	SDL_FreeSurface(background);
	SDL_FreeSurface(sp);
	SDL_FreeSurface(mp);
	SDL_FreeSurface(option);
	SDL_FreeSurface(about);
	SDL_FreeSurface(ex);
	SDL_FreeSurface(spritechar);
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

	// Load the images 
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

	if(intro == NULL) {
		printf("\nError details: %s\n", SDL_GetError());
		clean_up();	
	} else if(loading == NULL) {
		printf("\nError details: %s\n", SDL_GetError());
		clean_up();
 	} else { 

	}
	
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
						move();
						break;
					
					case SDLK_UP:     // up
						sp = load_image("images/buttons/sp_select.bmp");
						mp = load_image("images/buttons/mp.bmp");
						apply_surface(207, 189, mp, screen);
						apply_surface(207, 129, sp, screen);
						SDL_Flip(screen);
						break; 
					case SDLK_DOWN:   // down
						mp = load_image("images/buttons/mp_select.bmp");
						sp = load_image("images/buttons/sp.bmp");

						apply_surface(207, 189, mp, screen);
						apply_surface(207, 129, sp, screen);
						SDL_Flip(screen);
						break; 
				}
			}
		}
	}

	clean_up();
	return 0; 
}
