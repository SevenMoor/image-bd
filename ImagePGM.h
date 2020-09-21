#ifndef  IMAGEPGM_H
#define IMAGEPGM_H

#include "Image.h"
#include "Matrix.h"
#include "lib/def.h"

using namespace std;

class ImagePGM : public Image{
    private:
        byte** _bytes;
    public:
        ImagePGM(string filepath);
        ImagePGM(const ImagePGM&);
        ~ImagePGM();

        // Convolutions
        void lowPassFilter();
        void verticalGradient();
        void horizontalGrandient();
        void normalGrandient();

        // Histogram
        double* histogram();

        // Getter
        byte** bytes();

        // Operators
        void operator*(Matrix m);
        byte* operator[](int i);
};

#endif