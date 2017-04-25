////////////////////////////////////////////////
//  Hax World			              //
//  --------------------------------------    //
//  This is the version source for Hax World, //
//  What it does:			      //
//  Gets the games current version, so it can //
//  be printed on the screen		      //
////////////////////////////////////////////////

// Please note:
// At the moment I'm not sure how to make this automatic... so sadly you'll
// have to edit this each build. I'll be working on making this automatic later on :)
#include "define.h"
static int revision = 20; // revision number here

static void version() {
	printf("\nRevision: %i", revision);
}
