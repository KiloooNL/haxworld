#include "define.h"
#include "loadimage.h"
//#include "video.c"

static void clean_up_sprites() {
	SDL_FreeSurface(background);
	SDL_FreeSurface(sprite);
	SDL_Flip(screen);
	printf("Showing exit screen...\n");
	apply_surface(0, 0, quitter, screen);
	SDL_Flip(screen);
	SDL_Delay(1000);
	SDL_FreeSurface(quitter);
	SDL_Delay(1000);
	printf("Cleaned up successfully!\n");
	SDL_Quit();
}

static void single_player() {
	sprite = load_image("images/sprites/warrior/sprite1.bmp");
	apply_surface(0, 0, sprite, screen);
	SDL_Flip(screen);

	while(quit==false) {
		while(SDL_PollEvent(&event)) {
			// if user X'ed out of the window
			if(event.type == SDL_QUIT) {
				clean_up_sprites();
				quit = true;
				printf("\nUser has exited manually.\n");
			}
			//If a key was pressed 
			else if(event.type == SDL_KEYDOWN) {
				switch(event.key.keysym.sym) { 
					case SDLK_ESCAPE: // esc
						clean_up_sprites();
						break;
					case SDLK_LEFT:
						
						break;
					case SDLK_RIGHT:
						break;
					case SDLK_UP:
						break; 
					case SDLK_DOWN:
						break; 
				}
			}
		}
	}
}

static void multi_player() {
}
