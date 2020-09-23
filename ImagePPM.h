#ifndef  IMAGEPPM_H
#define IMAGEPPM_H

#include "Image.h"
#include "lib/def.h"

using namespace std;

class ImagePGM;

class ImagePPM : public Image{
    private:
        rgb8** _bytes;
        friend ImagePGM;

    public:
    	ImagePPM();
        explicit ImagePPM(string filepath);
        ImagePPM(const ImagePPM&);
        ImagePPM(const ImagePGM&);
        ~ImagePPM();

        void save(string path) override;

        double** histogram();

        rgb8** bytes();
};

#endif