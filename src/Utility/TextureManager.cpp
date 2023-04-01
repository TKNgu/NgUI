#include "TextureManager.hpp"
#include <glad/glad.h>
#include <iostream>
#include <stdexcept>
#include "Image.hpp"

using namespace il012e::utility;
using namespace il012e::graphic;
using namespace std;

//shared_ptr<Texture> TextureManager::getTexture(T id, string path) {
//    if (this->textures.find(id) == this->textures.end()) {
//		Image image(path);
//        auto texture = make_shared<Texture>();
//        switch (image.getNChannel()) {
//        case 3:
//            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
//				image.getWidth(), image.getHieght(), 0, GL_RGB,
//				GL_UNSIGNED_BYTE, image.getData());
//            break;
//        case 4:
//            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
//				image.getWidth(), image.getHieght(), 0, GL_RGBA,
//				GL_UNSIGNED_BYTE, image.getData());
//            break;
//        default:
//            break;
//        }
//        glGenerateMipmap(GL_TEXTURE_2D);
//        this->textures[id] = texture;
//    }
//    return this->textures[id];
//}
