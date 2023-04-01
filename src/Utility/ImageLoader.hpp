#ifndef ImageLoader_hpp
#define ImageLoader_hpp

#include <string>
#include <memory>
#include "Image.hpp"

namespace il012e::utility {
class ImageLoader {
public:
static std::shared_ptr<Image> LoadFromFile(std::string);
static std::shared_ptr<Image> Caro(int, int);
};
}
#endif
