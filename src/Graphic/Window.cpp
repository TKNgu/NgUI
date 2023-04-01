#include "Window.hpp"
#include <stdexcept>

using namespace std;
using namespace il012e::graphic;

Window::Window(unsigned int width, unsigned int height) {
	this->window = glfwCreateWindow(width, height, "", nullptr, nullptr);
	if (!this->window) {
		throw runtime_error("Error init window");
	}
	glfwSetFramebufferSizeCallback(this->window, [](GLFWwindow *, int width, int height) {
		glViewport(0, 0, width, height);
	});
	glfwMakeContextCurrent(this->window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
		glfwDestroyWindow(this->window);
        glfwTerminate();
        throw runtime_error("Error init GLAD");
    }
	//glEnable(GL_DEPTH_TEST);
}

Window::~Window() {
	glfwDestroyWindow(this->window);
}

void Window::input() {
    glfwPollEvents();
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
	for (auto &event : this->events) {
		if (glfwGetKey(this->window, event.keyCode) == GLFW_PRESS) {
			event.callBack();
		}
	}
}

void Window::clear(float r, float g, float b, float a) const {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}
