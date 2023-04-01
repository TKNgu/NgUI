#ifndef OpenGL_hpp
#define OpenGL_hpp

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace il012e::graphic {
class OpenGL {
public:
	static bool Init();
	static void Terminate(); 
};
}

#endif
