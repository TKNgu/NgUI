#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <map>
#include <memory>
#include <string>
#include <stdexcept>
#include <glad/glad.h>
#include "Texture.hpp"
#include "Image.hpp"
#include <iostream>
#include <memory>

namespace il012e::utility {
template<typename T> class TextureManager {
public:
	~TextureManager() {
		for (auto &item : this->textures) {
			delete item.second;
		}
	}

	void load(T id, std::shared_ptr<Image> image) {
		int32_t format;
  	 	switch (image->getNChannel()) {
		case 1:
			format = GL_RED;
			break;
  	 	case 3:
			format = GL_RGB;
  	 	    break;
  	 	case 4:
			format = GL_RGBA;
  	 	    break;
  	 	default:
			throw std::runtime_error("Format not suport");
  	 	}
		delete this->textures[id];
  	 	this->textures[id] = new il012e::graphic::Texture(
			image->getWidth(), image->getHieght(), format, image->getData(), format);
	}
	
    il012e::graphic::Texture &getTexture(T id) {
		auto found = this->textures.find(id);
		if (found == this->textures.end()) {
			throw std::runtime_error("Error found texture");
		}
		return *found->second;
	}
private:
    std::map<T, il012e::graphic::Texture *> textures;
};
}

#endif
