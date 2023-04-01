#include <iostream>
#include "Window.hpp"

using namespace std;
using namespace rg::graphic;

int main(int, char *[]) {
    cout << "Hello OpenGL" << endl;
	if (!InitGLFW()) {
		cout << "Error int GLFW" << endl;
		return -1;
	}
	Window window;
	while (!window.isClose()) {
		window.input();
		window.clear();
		window.render();
	}
return 0;
}
