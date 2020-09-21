#ifndef  IMAGE_H
#define IMAGE_H

#include <string>
#include <iostream>

using namespace std;

class Image{
    protected:
        int _width, _height;
        long _nrl, _nrh, _ncl, _nch;

        Image(string filepath);
        Image(const Image&);
        ~Image();

    public:
        int height() const;
        int width() const;
};


#endif