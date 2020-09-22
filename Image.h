#ifndef  IMAGE_H
#define IMAGE_H

#include <string>
#include <iostream>

using namespace std;

class Image{
    protected:
        int _width = 0;
        int _height = 0;
        long _nrl, _nrh, _ncl, _nch;

        Image();
        Image(const Image&);
        ~Image();

    public:
        int height() const;
        int width() const;
};


#endif