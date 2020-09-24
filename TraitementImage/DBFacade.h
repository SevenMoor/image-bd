#ifndef  DBFACADE_H
#define DBFACADE_H

#include "ImagePGM.h"
#include "ImagePPM.h"

class DBFacade{
    public:
        static double*   getHistogram(ImagePGM image);
        static double** getHistogram(ImagePPM image);
        static float getGradientAverage(ImagePGM image);
        static float getGradientAverage(ImagePPM image);
        static float getContourPointRate(ImagePPM image);
        static float getContourPointRate(ImagePGM image);
};

#endif