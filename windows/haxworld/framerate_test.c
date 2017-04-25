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

#include "define.h" 
int audio_rate = 22050;
Uint16 audio_format = AUDIO_S16SYS;
int audio_channels = 2;
int audio_buffers = 4096;
int channel;

Mix_Chunk *sound = NULL;

SDL_Surface* intro = NULL;   // intro
SDL_Surface* screen = NULL;  // screen
SDL_Surface* loading = NULL; // when loading
SDL_Event event;

void clean_up() {
	// Free surfaces
	SDL_FreeSurface(intro);
	SDL_FreeSurface(loading);

	SDL_Quit();
}

SDL_Surface *load_image(std::string filename) { 

	SDL_Surface* loadedImage = NULL; 
	SDL_Surface* optimizedImage = NULL; 

	loadedImage = SDL_LoadBMP(filename.c_str()); 

	//If nothing went wrong in loading the image 
	if(loadedImage != NULL) { 
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

	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) { 
		return 1; 
	} 
	
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE); 
	if(screen == NULL) { 
		printf("Error details: %s\n", SDL_GetError());
		return 1; 
	} 
 
	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
		printf("Unable to initialize audio: %s\n", Mix_GetError());
		exit(1);
	}
 
	sound = Mix_LoadWAV("data/music/toneage.wav");
	if(sound == NULL) {
		printf("Unable to load WAV file: %s\n", Mix_GetError());
	}
 
	channel = Mix_PlayChannel(-1, sound, 0);
	if(channel == -1) {
		fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
	}
	SDL_WM_SetCaption("Hax World", NULL); 

	// Load the images 
	intro = load_image("images/intro.bmp"); 
	loading = load_image("images/loading.bmp"); 

	if(intro == NULL) {
		printf("Error details: %s\n", SDL_GetError());
		clean_up();	
	} else if(loading == NULL) {
		printf("Error details: %s\n", SDL_GetError());
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
			if(event.type == SDL_QUIT) {
				while(Mix_Playing(channel) != 0);
				Mix_FreeChunk(sound);
				Mix_CloseAudio();
				//quit
				quit = true;
				if(quit == true) {
					printf("\nUser has exited manually.\n");
				}
			}
		}
	}

	clean_up();
	return 0; 
}