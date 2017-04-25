/////////////////////////////////////////////////
//  Hax World						           //
//  --------------------------------------     //
//  This is the intro/main menu for Hax World, //
//  What it does:							   //
//  Displays the introduction animation on     // 
//  the screen then jumps to the main menu     //
/////////////////////////////////////////////////

#include "game.cpp"
#include "version.cpp"

static void clean_up_menu() {
	return;
}

static bool init() { 

	// WELCOME MESSAGE
	printf("\nWelcome to HaxWorld\n");
	// REVISION
	version(); printf("\n");

	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		printf("\nError: %s", SDL_GetError());
		return false;
	}
	printf("SDL loaded successfully.\n");
	SDL_WM_SetCaption("haxworld", NULL);

	// Configure window
	printf("Configuring screen...");
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE); 
	if(screen == NULL) { 
		printf("\nCould not set resolution of: %ix%i \nError details: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		return false;
	} printf(" successful.\n");
	
	return true; 
}

static bool load_files() {
	background = load_image("images/background.bmp");
	if (background == NULL) { // if something went wrong
		printf("Error: SDL_Surface background is NULL, possible reasons:\n- background.bmp is missing or corrupt.\n");
	}
	return true;
}

static void clean_up() { // for when we want to quit, and exit everything
	printf("\nCleaning up...\n");

	printf("Showing exit screen...\n");
	quitter = load_image("images/quitter.bmp");

	apply_surface(0,0, quitter, screen);
	SDL_Flip(screen);
	SDL_Delay(1000);
	SDL_FreeSurface(quitter);

	printf("Cleaned up successfully!\n");
	SDL_Quit();
}


int main( int argc, char* args[] ) { 

	//Initialize 
	if(init() == false) { return 1; } 
	//Load the files 
	if(load_files() == false) { return 1; }

	apply_surface(0,0, background, screen);
	SDL_Flip(screen);
	SDL_Delay(500);
	SDL_FreeSurface(background);

	while(quit==false) {
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				quit = true;
			}

			// KEY HANDLES
			else if(event.type == SDL_KEYDOWN) { // If a key is pressed down
				switch(event.key.keysym.sym) { 

					/* ANYTIME KEY HANDLES */
					case SDLK_ESCAPE: // esc	
						printf("\nKey press: SDLK_ESCAPE\n");
						quit = true;
						clean_up();
						break;
					case SDLK_UP: // up
						break;
					case SDLK_DOWN: // down
						break;
					case SDLK_LEFT: // left
						break;
					case SDLK_RIGHT: // right
						break;

					/* MENU KEY HANDLES */
					case SDLK_F9:
						printf("Event (key press): SDLK_F9\n");
						// single player
						background = load_image("images/background/background.bmp");
						apply_surface(0,0, background, screen);
						sprite = load_image("images/sprites/Image1.bmp");
						apply_surface(10,250, sprite, screen);
						SDL_Flip(screen);
						SDL_FreeSurface(sprite);
						single_player(); // begin single player
						//static bool single=true;

						break;
					case SDLK_F10:
						printf("Event (key press): SDLK_F10\n");
						// multi player
						break;
					case SDLK_F11:
						printf("Event (key press): SDLK_F11\n");
						// options
						break;
				}
			}
		}
	}
	
	printf("bool quit = true. Exiting now!\n");
	// clean_up();
	SDL_Quit();
	return 0;
}