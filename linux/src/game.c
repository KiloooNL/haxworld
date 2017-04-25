#include "define.h"
#include "animation.c"
#include "loadimage.h"
//#include "video.c"


static void single_player() {
	sprite = load_image("images/sprites/warrior/sprite1.bmp");
	apply_surface(0, 0, sprite, screen);
	SDL_Flip(screen);

}

static void multi_player() {
}
