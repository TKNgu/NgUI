#include "TextureManager.hpp"
#include <glad/glad.h>
#include <iostream>
#include <stdexcept>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace rg::graphic;
using namespace std;

TextureManager &TextureManager::GetInstance() {
    static TextureManager instance;
    return instance;
}

TextureManager::TextureManager() { }

shared_ptr<Texture> TextureManager::getTexture(string path) {
    if (this->textures.find(path) == this->textures.end()) {
        auto texture = make_shared<Texture>();
        int width, height, nrChannels;
        unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
        if (data) {
            switch (nrChannels) {
            case 3:
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
                break;
            case 4:
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
                break;
            default:
                break;
            }
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else {
            throw runtime_error("Failed to load texture " + path);
        }
        stbi_image_free(data);
        this->textures[path] = texture;
    }
    return this->textures[path];
}
