// The attributes of the screen 
const int SCREEN_WIDTH = 640; 
const int SCREEN_HEIGHT = 480; 
const int SCREEN_BPP = 32;
int ERROR_NUM = 0;

SDL_Surface* intro = NULL;   // intro
SDL_Surface* screen = NULL;  // screen
SDL_Surface* loading = NULL; // when loading

SDL_Event event;

// Clean Up
void clean_up() {
	SDL_FreeSurface(intro); // free surface, release memory so there's no leaks
	SDL_FreeSurface(loading);
	SDL_FreeSurface(screen); // shit, forgot to put this in... realized on R07
	printf("\nCleaning up...");
	printf("\nCleaned up successfully\n");
	SDL_Quit();		// quit
	printf("\nErrors: %i \n",ERROR_NUM);
}
