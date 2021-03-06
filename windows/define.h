#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <string> 

#ifndef __DEFINE_H__
#define __DEFINE_H__

#define NUM_SPRITES 200

// Main Menu
#define SPRITE_MENU 0
#define SPRITE_LOBBY 1
#define SPRITE_SERVER_HIGHLIGHT 2
#define SPRITE_FONT_WHITE 3
#define SPRITE_FONT_RED 4
#define SPRITE_FONT_BLACK 5
#define SPRITE_FONT_BLUE 6
#define DOWN_ARROW 7
#define SPRITE_OPTIONS 8
#define SPRITE_QUITTER 9
#define SPRITE_MENU_TOP 10

// Screen settings
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP 32

// Sprites
#define SPRITE_SIZE 32
#define SPRITE_HEIGHT 0
#define SPRITE_WIDTH 0

// Error numbers (for debugging)
#define ERROR_NUM 0

// Other stuff
static bool quit = false;
static SDL_Event event;


/* Method signatures */
// alloc.c
void *xmalloc(size_t n);
void *xrealloc(void *old, size_t n);

void drawText (SDL_Surface *screen, int font, int x, int y, const char* text);

// Audio
static Mix_Chunk *sound = NULL;

/* Enumerations */
typedef enum {
	DIR_NONE = 0x0,
	DIR_UP = 0x1,
	DIR_DOWN = 0x2,
	DIR_LEFT = 0x4,
	DIR_RIGHT = 0x8,
} MovementDirection;

typedef struct config {
	char *name;
	int fullscreen;
	int spriteonmenu;
	char *map;
	int vol_music;
	int vol_sound;
} Config;

typedef struct animation {
	int frames;
	int next;
	
	int x;
	int y;
} Animation;

class Character { 
	private:  
		int x, y; 
		int xVel, yVel; 

	public: 
		//Initializes the variables 
		Character(); 
		void handle_input(); 
		void move(); 
		void show(); 
};

// Text
void drawText(SDL_Surface *screen, TTF_Font* font, const char* text, int x, int y);

// Apply Surface
static void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination) { 

	SDL_Rect offset; 

	offset.x = x; 
	offset.y = y;
	
	SDL_BlitSurface(source, NULL, destination, &offset); 
}

#endif