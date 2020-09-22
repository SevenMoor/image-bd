#include "ImagePGM.h"

#include <cstring>

#include "lib/nralloc.h"
#include "lib/nrio.h"

ImagePGM::ImagePGM(string filepath){
    char *cpath;
	strcpy(cpath, filepath.c_str());
	_bytes = LoadPGM_bmatrix(cpath, &_nrl, &_nrh, &_ncl, &_nch);
	_width = _nrh - _nrl;
	_height = _nch - _ncl;
}


ImagePGM::ImagePGM(const ImagePGM& image){
    _nrl = image._nrl;
	_nrh = image._nrh;
	_ncl = image._ncl;
	_nch = image._nch;
	_width = _nrh - _nrl;
	_height = _nch - _ncl;
	_bytes = bmatrix(_nrl, _nrh, _ncl, _nch);

	for (int row = 0; row<_width; ++row)
	{
		for (int col = 0; col<_height; ++col)
		{
			_bytes[row][col] = image._bytes[row][col];
		}
	}
}


ImagePGM::~ImagePGM(){
    free(_bytes);
}


void ImagePGM::lowPassFilter(){

}


void ImagePGM::verticalGradient(){

}


void ImagePGM::horizontalGrandient(){

}


void ImagePGM::normalGrandient(){

}


double* ImagePGM::histogram(){

}


byte** ImagePGM::bytes(){

}


void ImagePGM::operator*(Matrix m){
    
}


byte* ImagePGM::operator[](int i){

}