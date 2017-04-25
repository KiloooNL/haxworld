//////////////////////////////////////////////
//  Hax World			            //
//  --------------------------------------  //
//  This is the animation source for        //
//  HaxWorld.				    //
//					    //
//  What it does:			    //
//  Defines basic concepts of moving an     //
//  object around on the screen. 	    //
//////////////////////////////////////////////

#include "define.h"
#include "loadimage.h"

// Character settings
#define CHR_HEIGHT 0
#define CHR_WIDTH 0

SDL_Surface* chr = NULL;
static int speed; // character speed

// The main sprite that will move around on the screen 
class character { 
	private: 
		int x, y; //The X and Y offsets of the character
		int xVel, yVel; //The velocity of the character 

	public:
		character(); //Initializes the variables 
		void handle_input(); //Takes key presses and adjusts the character's velocity 
		void move();  //Moves the character 
		void show();  //Shows the character on the screen 
};

character::character() {
	//Initialize the offsets 
	static int x = 0; 
	static int y = 0; 
	//Initialize the velocity 
	static int xVel = 0; 
	static int yVel = 0; 
}

void character::handle_input() { 
	//If a key was pressed 
	if(event.type == SDL_KEYDOWN) { 
		//Adjust the velocity 
		switch(event.key.keysym.sym) { 
			case SDLK_UP: yVel -= CHR_HEIGHT / 2; break; 
			case SDLK_DOWN: yVel += CHR_HEIGHT / 2; break; 
			case SDLK_LEFT: xVel -= CHR_WIDTH / 2; break; 
			case SDLK_RIGHT: xVel += CHR_WIDTH / 2; break; 
		} 
	}
	//If a key was released 
	else if(event.type == SDL_KEYUP) { 
		//Adjust the velocity 
		switch(event.key.keysym.sym) { 
			case SDLK_UP: yVel += CHR_HEIGHT / 2; break; 
			case SDLK_DOWN: yVel -= CHR_HEIGHT / 2; break; 
			case SDLK_LEFT: xVel += CHR_WIDTH / 2; break; 
			case SDLK_RIGHT: xVel -= CHR_WIDTH / 2; break; 
		} 
	} 
}

void character::move() { 
//Move the character left or right 
	x += xVel; //If the character went too far to the left or right 
		if((x < 0) || (x + CHR_WIDTH > SCREEN_WIDTH)) { 
			//move back 
			x -= xVel;
		}
 	//Move the character up or down 
	y += yVel; //If the character went too far up or down 
		if((y < 0) || (y + CHR_HEIGHT > SCREEN_HEIGHT)) { 
			//move back 
			y -= yVel; 
		} 
} 

void character::show() { 
	chr = load_image("images/sprites/warrior/sprite1.bmp");
	//Show the character 
	apply_surface(x, y, chr, screen); 
} 

/*While the user hasn't quit 
void whileopen() {
	while(quit == false) { 
	//Start the frame timer fps.start();
		while(SDL_PollEvent(&event)) { 
			character::handle_input(); 
			//If the user has Xed out the window 
				if( event.type == SDL_QUIT ) {
					quit = true; 
				} 
			}  
		character::move(); //Fill the screen white 
		SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF)); 
		//Show the character on the screen 
		character::show(); //Update the screen
 		if(SDL_Flip(screen) == -1) { 
			SDL_Quit; 
		} 
 	} 
}*/
