#include "video.c"

static void single_player() {
	
	//Make the sprite 
	sprite_motion mySprite;

    //While the user hasn't quit
    while(quit == false)
    {
        
        //While there's events to handle
        while(SDL_PollEvent(&event))
        {
            mySprite.handle_input();

            if(event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        mySprite.move();
        
        //Fill the screen white
        SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
        
        mySprite.show();
        
        //Update the screen
        if(SDL_Flip(screen) == -1)
        {
			SDL_Quit();
           // return 1;    
        }
    }
}