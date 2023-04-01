#include "Image.hpp"
#include <stdexcept>
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
#include <iostream>

using namespace il012e::utility;
using namespace std;

Image::Image(int width, int height, int nChannel,
	void *data, ReleaseData release) :
	width(width), height(height), nChannel(nChannel),
	data(data), release(release) { }

Image::~Image() {
	this->release(this->data);
}
