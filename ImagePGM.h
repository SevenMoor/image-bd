#ifndef  IMAGEPGM_H
#define IMAGEPGM_H

#include "Image.h"
#include "lib/def.h"

using namespace std;

class Matrix;
class ImagePPM;

class ImagePGM : public Image{
    private:
        byte** _bytes;
        friend ImagePPM;

    public:
        ImagePGM();
        ImagePGM(string filepath);
        ImagePGM(const ImagePGM&);
        ImagePGM(const ImagePPM&);
        ~ImagePGM();

        void save(string path);

        // Convolutions
        ImagePGM& lowPassFilter();
        ImagePGM& verticalGradient();
        ImagePGM& horizontalGradient();
        ImagePGM& gradientNormal();

        // Histogram
        double* histogram();

        // Getter
        byte** bytes();

        // Operators
        ImagePGM& operator*(Matrix &m);
        byte* operator[](int i);
};

#endif