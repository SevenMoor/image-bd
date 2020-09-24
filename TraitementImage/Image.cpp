#include "Image.h"

Image::Image() {
	_width = _height = _nrl = _nrh = _ncl = _nch = 0;

}

Image::Image(string filepath) : Image() {}

Image::Image(const Image& image) {
	_width = image._width;
	_height = image._height;
	_nrl = image._nrl;
	_nrh = image._nrh;
	_ncl = image._ncl;
	_nch = image._nch;
}

Image::~Image(){}

int Image::height() const{
    return _height;
}

int Image::width() const{
    return _width;
}