#include "Sprite.hpp"
#include <string>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.hpp"

using namespace il012e::utility;
using namespace il012e::graphic;
using namespace std;

Sprite::Sprite(Texture &texture) : texture(texture), center(0.f, 0.f) {
	static const string vertexShaderSource = "#version 460 core\n"
		"layout (location = 0) in vec3 position;\n"
		"layout (location = 1) in vec2 texCoord;\n"
		"out vec2 ourTexCoord;\n"
		"uniform mat4 matrix;\n"
	    "void main() {\n"
	    "   gl_Position = matrix * vec4(position.x, position.y, position.z, 1.f);\n"
		"	ourTexCoord = texCoord;\n"
	    "}\0";

	static const string fragmentShaderSource = "#version 460 core\n"
		"in vec2 ourTexCoord;\n"
		"uniform sampler2D ourTexture;\n"
	    "out vec4 FragColor;\n"
	    "void main() {\n"
		"	vec4 texColor = texture(ourTexture, ourTexCoord);\n"
		"	if (texColor.a < 0.1) {\n"
		"		discard;\n"
		"	}\n"
	    "   FragColor = texture(ourTexture, ourTexCoord);\n"
	    "}\0";

	Shader vertexShader(vertexShaderSource, GL_VERTEX_SHADER);
	Shader fragmentShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
	this->program.attach(vertexShader);
	this->program.attach(fragmentShader);
	this->program.link();
	
	float width = texture.getWidth();
	float height = texture.getHeight();
	auto tmpMax = width > height ? width : height;
	auto glX = width / tmpMax;
	auto glY = height / tmpMax;

	const float vertices[] = {
	    // positions	 // texture coords
	     glX,  glY, 0.f, 1.f, 1.f,   // top right
	     glX, -glY, 0.f, 1.f, 0.f,   // bottom right
	    -glX, -glY, 0.f, 0.f, 0.f,   // bottom left
	    -glX,  glY, 0.f, 0.f, 1.f    // top left 
	};
    const unsigned int indices[] = {  // note that we start from 0!
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(0));
    glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float))); 
	glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0); 
}

Sprite::~Sprite() {
    glDeleteVertexArrays(1, &this->VAO);
    glDeleteBuffers(1, &this->VBO);
    glDeleteBuffers(1, &this->EBO);
}

void Sprite::render(const glm::mat4 parentMatrix) const {
	this->program.use();
	glBindVertexArray(this->VAO);
	glActiveTexture(GL_TEXTURE0);
	this->texture.bind();
	glm::mat4 matrix = parentMatrix * this->model;
	this->program.setUniform("matrix", glm::value_ptr(matrix));
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	this->texture.unbin();
	glBindVertexArray(0);
}
