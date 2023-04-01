#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <map>
#include <memory>
#include <string>
#include "Texture.hpp"

namespace rg::graphic {
class TextureManager {
public:
    static TextureManager &GetInstance();
    std::shared_ptr<Texture> getTexture(std::string);
private:
    TextureManager();
    TextureManager(TextureManager &) = delete;
private:
    std::map<std::string, std::shared_ptr<Texture>> textures;
};
}
#endif