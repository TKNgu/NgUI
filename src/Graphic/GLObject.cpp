#include "GLObject.hpp"
#include "Shader.hpp"
#include "TextureManager.hpp"

using namespace il012e::graphic;
using namespace il012e::utility;
using namespace std;

//Need Update
GLObject::GLObject( Texture &texture) : texture(texture) {
	static const string vertexShaderSource = "#version 330 core\n"
	    "layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aColor;\n"
		"layout (location = 2) in vec2 aTexCoord;\n"
		"out vec3 ourColor;\n"
		"out vec2 ourTexCoord;\n"
	    "void main()\n"
	    "{\n"
	    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"	ourColor = aColor;\n"
		"	ourTexCoord = aTexCoord;\n"
	    "}\0";

	static const string fragmentShaderSource = "#version 330 core\n"
	    "out vec4 FragColor;\n"
		"in vec3 ourColor;\n"
		"in vec2 ourTexCoord;\n"
		"uniform sampler2D ourTexture;\n"
	    "void main()\n"
	    "{\n"
	    //"   FragColor = vec4(ourColor, 1.0f);\n"
	    "   FragColor = texture(ourTexture, ourTexCoord);\n"
	    "}\n\0";

	Shader vertexShader(vertexShaderSource, GL_VERTEX_SHADER);
	Shader fragmentShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
	this->program.attach(vertexShader);
	this->program.attach(fragmentShader);
	this->program.link();
	
	static const float vertices[] = {
	    // positions          // colors           // texture coords
	     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
	     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
	    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
	    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
	};
    static const unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->EBO);
    glBindVertexArray(this->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(0));
    glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float))); 
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0); 
}

GLObject::~GLObject() {
    glDeleteVertexArrays(1, &this->VAO);
    glDeleteBuffers(1, &this->VBO);
    glDeleteBuffers(1, &this->EBO);
}

void GLObject::render() const {
	glBindVertexArray(this->VAO);
	this->program.use();
	glActiveTexture(GL_TEXTURE0);
	this->texture.bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
