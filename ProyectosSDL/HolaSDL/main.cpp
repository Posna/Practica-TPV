
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include "Game.h"

using namespace std;

using uint = unsigned int;

int main(int argc, char* argv[]){
	Game* game = new Game();
	game->run();
	game->~Game(); //delete
	return 0;
}