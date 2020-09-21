#ifndef  IMAGE_H
#define IMAGE_H

#include <string>
#include <iostream>

using namespace std;

class Image{
    protected:
        int _height;
        int _width;

        Image(string filepath);
        Image(const Image&);
        ~Image();

    public:
        int height() const;
        int width() const;
};


#endif