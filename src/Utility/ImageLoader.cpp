#include "ImageLoader.hpp"
#include <stdexcept>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace il012e::utility;
using namespace std;

shared_ptr<Image> ImageLoader::LoadFromFile(string filePath) {
	int width, height, nChannel;
	stbi_set_flip_vertically_on_load(true);
	auto data = stbi_load(filePath.c_str(),
		&width, &height, &nChannel, 0);
	if (!data) {
		throw runtime_error("Error load " + filePath);
	}
	return make_shared<Image>(width, height, nChannel,
		data, stbi_image_free);
}

shared_ptr<Image> ImageLoader::Caro(int width, int height) {
	auto data = new unsigned char[width * height];
	auto hafWidth = width >> 1;
	for (unsigned int indexX = 0; indexX < width; indexX++) {
		for (unsigned int indexY = 0; indexY < height; indexY++) {
			if (indexX < hafWidth) {
				data[indexY * width + indexX] = 255;
			}
			else {
				data[indexY * width + indexX] = 0;
			}
		}
	}
	return make_shared<Image>(width, height, 1, data, [](void *data) {
		delete[] (unsigned char *)(data);
	});
}
