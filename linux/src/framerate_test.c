//////////////////////////////////////////////////
//  Hax World			  	        //
//  --------------------------------------	//
//  This is the frame rate source for Hax World //
//  What it does:				//
//  Tests client's maximum frame rate	 	// 
//					    	//
//  Coded by Ben Weidenhofer, under the     	//
//  GPL license,  bla bla bla open source!  	//
//////////////////////////////////////////////////

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <string> 

// The attributes of the screen 
const int SCREEN_WIDTH = 640; 
const int SCREEN_HEIGHT = 480; 
const int SCREEN_BPP = 32;

SDL_Surface* screen = NULL;  // screen

SDL_Event event;

//The timer 
class Timer { 
private: 
int startTicks; 
int pausedTicks; 
bool paused; 
bool started; 

public: 
Timer(); 
void start(); 
void stop(); 
void pause(); 
void unpause(); 
int get_ticks(); 
bool is_started(); 
bool is_paused(); 
}; 

Timer::Timer() { 
//Initialize the variables 
startTicks = 0; 
pausedTicks = 0; 
paused = false; 
started = false; 
} 

void Timer::start() { 
started = true; 
paused = false; 
startTicks = SDL_GetTicks(); 
} 

void Timer::stop() { 
started = false; 
paused = false; 
}

int Timer::get_ticks() { 
	if( started == true ) { 
		if( paused == true ) { 
		return pausedTicks; 
	} else { 
		return SDL_GetTicks() - startTicks; 
		} 
	}
return 0; 
}  

void Timer::pause() { 
	if( ( started == true ) && ( paused == false ) ) { 
	paused = true; 
	pausedTicks = SDL_GetTicks() - startTicks; 
	} 
} 

void Timer::unpause() { 
	if( paused == true ) { 
		paused = false; 
		startTicks = SDL_GetTicks() - pausedTicks; 
		pausedTicks = 0; 
	} 
} 

bool Timer::is_started() { 
	return started; 
} 
bool Timer::is_paused() { 
return paused; 
} 

void stuff() {

	//Open the font 
	font = TTF_OpenFont( "lazy.ttf", 30 ); 
	Timer myTimer; 
	TTF_RenderText_Solid( font, "Press S to start or stop the timer", textColor ); 
	TTF_RenderText_Solid( font, "Press P to pause or unpause the timer", textColor );
}

int main(int argc, char* args[]) { 
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) { 
		return 1;
	}
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE); 
	if(screen == NULL)  { 
		return 1;
	} 

	int frame = 0; 
	Timer fps; 
	Timer update; 


	myTimer.start();
	while( quit == false ) { 
}
