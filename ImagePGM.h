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
        ~ImagePGM();
        byte** bytes();
        ImagePGM lowPassFilter();
        ImagePGM operator*(Matrix m);
        ImagePGM verticalGradient();
        ImagePGM horizontalGrandient();
        ImagePGM normalGrandient();
        double* histogram();
};

#endif