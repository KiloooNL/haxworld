//////////////////////////////////////////////
//  Hax World			            //
//  --------------------------------------  //
//  This is the intro source for Hax World, //
//  What it does:			    //
//  Displays the introduction animation on  // 
//  the screen then jumps to the main menu  //
//////////////////////////////////////////////

#include "define.h"
#include "button.c"
#include "version.c"
int audio_rate = 22050;
Uint16 audio_format = AUDIO_S16SYS;
int audio_channels = 2;
int audio_buffers = 4096;
int channel;

Mix_Chunk *sound = NULL;

SDL_Surface* intro = NULL;   // intro
SDL_Surface* screen = NULL;  // screen
SDL_Surface* loading = NULL; // when loading
SDL_Surface* quitter = NULL; // picture for exit B-)
SDL_Surface* background = NULL;
SDL_Surface* spritechar = NULL; // client's character sprite

// buttons
SDL_Surface* sp = NULL;
SDL_Surface* mp = NULL;
SDL_Surface* option = NULL;
SDL_Surface* about = NULL;
SDL_Surface* ex = NULL;

SDL_Event event;

static void clean_up() {
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
		clean_up();	
	}

	return optimizedImage; 
} 

int main( int argc, char* args[] ) { 


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
	
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE); 
	if(screen == NULL) { 
		printf("\nCould not set resolution of: %ix%i \nError details: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		return 1; 
	} 
 
	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
		printf("\nUnable to initialize audio: %s\n", Mix_GetError());
		exit(1);
	}
 
	sound = Mix_LoadWAV("data/music/toneage.wav");
	if(sound == NULL) {
		printf("\nUnable to load WAV file: %s\n", Mix_GetError());
	}
 
	channel = Mix_PlayChannel(-1, sound, 0);
	if(channel == -1) {
		fprintf(stderr, "\nUnable to play WAV file: %s\n", Mix_GetError());
	}
	SDL_WM_SetCaption("Hax World", NULL); 

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

	bool quit = false;
	
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
					case SDLK_ESCAPE:
						quit = true;
						break;
					case SDLK_UP: 
						sp = load_image("images/buttons/sp_select.bmp");
						mp = load_image("images/buttons/mp.bmp");
						apply_surface(207, 189, mp, screen);
						apply_surface(207, 129, sp, screen);
						SDL_Flip(screen);
						break; 
					case SDLK_DOWN: 
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
