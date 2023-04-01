#include "Window.hpp"
#include <stdexcept>

using namespace std;

bool rg::graphic::InitGLFW() {
    if (glfwInit() == GLFW_FALSE) {
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
return true;
}

void FrameBufferSizeCallback(GLFWwindow *, int width, int height) {
    glViewport(0, 0, width, height);
}

rg::graphic::Window::Window() :
    window(glfwCreateWindow(800, 600, "Sample", nullptr, nullptr)) {
    if (this->window == nullptr) {
        throw runtime_error("Error init window");
    }
    glfwSetFramebufferSizeCallback(this->window, FrameBufferSizeCallback);

    glfwMakeContextCurrent(this->window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        glfwTerminate();
        throw runtime_error("Error init GLAD");
    }
	glEnable(GL_DEPTH_TEST);
}

rg::graphic::Window::~Window() {
    glfwTerminate();
}

#ifdef _GLFW_X11
GLXContext rg::graphic::Window::getGLXContext() {
    return glfwGetGLXContext(this->window);
}
#endif

bool rg::graphic::Window::isClose() {
    return glfwWindowShouldClose(this->window);
}

void rg::graphic::Window::input() {
    glfwPollEvents();
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void rg::graphic::Window::clear() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void rg::graphic::Window::render() {
    glfwSwapBuffers(this->window);
}
