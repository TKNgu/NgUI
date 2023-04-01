#ifndef Window_hpp
#define Window_hpp

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <functional>
#include <vector>

namespace il012e::graphic {
class Window {
public:
struct EventHandle {
	int keyCode;
	std::function<void ()> callBack;
};
public:
    Window(unsigned int = 800, unsigned int = 640);
    ~Window();
	inline bool getIsClose() const {
    	return glfwWindowShouldClose(this->window);
	}
    void input();
    void clear(float = 0.2f, float = 0.3f, float = 0.3f, float = 1.0f) const;
	inline void render() const {
    	glfwSwapBuffers(this->window);
	}
	inline void registerEvent(EventHandle event) {
		this->events.push_back(event);
	}
private:
    GLFWwindow *window = nullptr;
	std::vector<EventHandle> events;
};
}
#endif
