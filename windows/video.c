#include "loadimage.h"

/* USED BY SINGLE PLAYER */
class sprite_motion {

	private:
    int x, y;
    int xVel, yVel; //The velocity of the dot
    
    public:
    //Initializes the variables
    sprite_motion();
    
    //Takes key presses and adjusts the sprite's velocity
    void handle_input();
    
    //Moves the sprite
    void move();
    
    //Shows the sprite on the screen
    void show();
};

sprite_motion::sprite_motion()
{
    x = 0;
    y = 0;
    
    xVel = 0;
    yVel = 0;
}

void sprite_motion::handle_input()
{
    if(event.type == SDL_KEYDOWN)
    {
        //Adjust the velocity
        switch(event.key.keysym.sym)
        {
            case SDLK_UP: yVel -= SPRITE_HEIGHT / 2; break;
            case SDLK_DOWN: yVel += SPRITE_HEIGHT / 2; break;
            case SDLK_LEFT: xVel -= SPRITE_WIDTH / 2; break;
            case SDLK_RIGHT: xVel += SPRITE_WIDTH / 2; break;    
        }
    }
	
	//If a key was released
    else if(event.type == SDL_KEYUP)
    {
        //Adjust the velocity
        switch(event.key.keysym.sym)
        {
            case SDLK_UP: yVel += SPRITE_HEIGHT / 2; break;
            case SDLK_DOWN: yVel -= SPRITE_HEIGHT / 2; break;
            case SDLK_LEFT: xVel += SPRITE_WIDTH / 2; break;
            case SDLK_RIGHT: xVel -= SPRITE_WIDTH / 2; break;   
        }        
    }
}

void sprite_motion::move()
{
    //Move the dot left or right
    x += xVel;
    
    //If the dot went too far to the left or right
    if((x < 0) || (x + SPRITE_WIDTH > SCREEN_WIDTH))
    {
        x -= xVel;    
    }
    
    //Move the dot up or down
    y += yVel;
    
    //If the dot went too far up or down
    if((y < 0) || (y + SPRITE_HEIGHT > SCREEN_HEIGHT))
    {
        y -= yVel;    
    }
}

void sprite_motion::show()
{
    apply_surface(x, y, sprite, screen);
}