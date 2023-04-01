#ifndef Image_hpp
#define Image_hpp

#include <string>
#include <functional>

namespace il012e::utility {
class Image {
public:
	typedef std::function<void (void *)> ReleaseData;
public:
	Image(int, int, int, void *, ReleaseData);
	~Image();
	inline int getWidth() const {
		return this->width;
	}
	inline int getHieght() const {
		return this->height;
	}
	inline int getNChannel() const {
		return this->nChannel;
	}
	inline void *getData() const {
		return this->data;
	}
private:
	void *data;
	ReleaseData release;
	int width;
	int height;
	int nChannel;
};
}

#endif
