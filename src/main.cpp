#include <iostream>
#include "OpenGL.hpp"
#include "Game.hpp"

using namespace std;
using namespace il012e::graphic;

int main(int, char *[]) {
	if (!OpenGL::Init()) {
		cout << "Error init glfw" << endl;
		return 1;
	}
	il012e::game::Game game;
	game.run();
	OpenGL::Terminate();
    return 0;
}
