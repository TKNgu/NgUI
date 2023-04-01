#include "Texture.hpp"
#include <glad/glad.h>
#include <iostream>

using namespace il012e::graphic;
using namespace std;

Texture::Texture(GLsizei width, GLsizei height, GLint internalformat, void *data, GLint format) {
	static int count = 0;
    glGenTextures(1, &this->texture);
    glBindTexture(GL_TEXTURE_2D, this->texture);
	float borderColor[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  	glTexImage2D(GL_TEXTURE_2D, 0, internalformat, width, height,
			0, format, GL_UNSIGNED_BYTE, data);
  	glGenerateMipmap(GL_TEXTURE_2D);
	this->width = width;
	this->height = height;
}

Texture::~Texture() {
    glDeleteTextures(1, &this->texture);
}
