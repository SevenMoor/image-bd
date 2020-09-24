#include "DBFacade.h"

double*   DBFacade::getHistogram(ImagePGM image){
    return image.histogram();
}


 double** DBFacade::getHistogram(ImagePPM image){
     return image.histogram();
 }


 float DBFacade::getGradientAverage(ImagePGM image){
     ImagePGM grad = image.lowPassFilter();
     grad = grad.sobel();
     grad = grad.threshold(15);
     
     byte** content = image.bytes();
     double sum = 0;
     double counter = 0;
    for(int i=0;i<image.width(); i++){
        for (int j=0;j<image.height();j++){
            counter++;
            sum += content[i][j];
        }
    }
    return (float) sum/counter;
 }


 float DBFacade::getContourPointRate(ImagePGM image){
     ImagePGM grad = image;
     grad.lowPassFilter();
     grad.sobel();
     grad.threshold(15);
     
     byte** content = grad.bytes();
     double counter = 0;
    for(int i=0;i<image.width(); i++){
        for (int j=0;j<image.height();j++){
            if(content[i][j]==255){
                counter++;
            }
        }
    }
    return (float) counter/(image.width()*image.height());
 }


 float DBFacade::getGradientAverage(ImagePPM image){
     ImagePGM good = image;
     return getGradientAverage(good);
 }


float DBFacade::getContourPointRate(ImagePPM image){
    ImagePGM good = image;
    return getContourPointRate(good);
}