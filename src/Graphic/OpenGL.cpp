#include "OpenGL.hpp"

using namespace il012e::graphic;

bool OpenGL::Init() {
	if (glfwInit() == GLFW_FALSE) {
		return false;
	}
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	return true;
}

void OpenGL::Terminate() {

}
