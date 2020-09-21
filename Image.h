#ifndef  IMAGE_H
#define IMAGE_H

#include <string>
#include <iostream>

using namespace std;

class Image{
    protected:
        int _height;
        int _width;
    public:
        Image(string filepath);
        ~Image();
        int height();
        int width();
};


#endif