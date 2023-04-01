#ifndef Window_hpp
#define Window_hpp

#include <glad/glad.h>
#define GLFW_EXPOSE_NATIVE_X11
#define GLFW_EXPOSE_NATIVE_GLX
#include <GLFW/glfw3.h>
#ifdef _GLFW_X11
#include <GLFW/glfw3native.h>
#endif

namespace rg::graphic {
bool InitGLFW();

class Window {
public:
    Window();
    ~Window();
#ifdef _GLFW_X11
    GLXContext getGLXContext();
#endif
    bool isClose();
    void input();
    void clear();
    void render();
private:
    GLFWwindow *window = nullptr;
};
}
#endif