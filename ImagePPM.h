#ifndef  IMAGEPPM_H
#define IMAGEPPM_H

#include "Image.h"
#include "Matrix.h"
#include "lib/def.h"

using namespace std;

class ImagePPM : public Image{
    private:
        rgb8** _bytes;

    public:
        ImagePPM(string filepath);
        ImagePPM(const ImagePPM&);
        ~ImagePPM();

        void save(string path);

        double** histogram();

        rgb8** bytes();
};

#endif