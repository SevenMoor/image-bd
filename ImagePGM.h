#ifndef  IMAGEPGM_H
#define IMAGEPGM_H

#include "Image.h"
#include "lib/def.h"

using namespace std;

class Matrix;
class ImagePPM;

class ImagePGM : public Image{
    private:
        byte** _bytes{};
        friend ImagePPM;

    public:
        ImagePGM();
        explicit ImagePGM(const string &filepath);
        ImagePGM(const ImagePGM&);
        ImagePGM(const ImagePPM&);
        ~ImagePGM();

        void save(string path) override;

        // Convolutions
        ImagePGM& lowPassFilter();
        ImagePGM& sobel();
        ImagePGM& threshold(unsigned char i);

        // Histogram
        double* histogram();

        // Getter
        byte** bytes();

        // Operators
        ImagePGM& operator*(Matrix &m);
        byte* operator[](int i);
};

#endif