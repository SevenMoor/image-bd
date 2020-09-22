#ifndef  DBFACADE_H
#define DBFACADE_H

class DBFacade{
    public:
        static byte*   getHistogram(ImagePGM image);
        static byte** getHistogram(ImagePPM image);
        static float getGradientAverage(ImagePGM image);
        static float getContourPointRate(ImagePGM image);
};

#endif