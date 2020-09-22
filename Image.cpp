#include "Image.h"

Image::Image() {}

Image::Image(const Image& image) {

}

Image::~Image(){}

int Image::height() const{
    return _height;
}

int Image::width() const{
    return _width;
}