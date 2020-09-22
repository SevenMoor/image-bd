#include "ImagePGM.h"
#include "ImagePPM.h"
#include "Matrix.h"
#include "lib/nralloc.h"
#include "lib/nrio.h"

#include <cstring>
#include <cmath>

ImagePGM::ImagePGM() : Image() {}

ImagePGM::ImagePGM(string filepath) : Image(filepath) {
	char cpath[filepath.size()];
	strcpy(cpath, filepath.c_str());
	_bytes = LoadPGM_bmatrix(cpath, &_nrl, &_nrh, &_ncl, &_nch);
	_width = _nrh - _nrl;
	_height = _nch - _ncl;
}

ImagePGM::ImagePGM(const ImagePGM& image) : Image(image) {
	_bytes = bmatrix(_nrl, _nrh, _ncl, _nch);

	for (int row = 0; row < _width; ++row)
	{
		for (int col = 0; col < _height; ++col)
		{
			_bytes[row][col] = image._bytes[row][col];
		}
	}
}

ImagePGM::ImagePGM(const ImagePPM& image) : Image(image) {
	_bytes = bmatrix(_nrl, _nrh, _ncl, _nch);

	for (int row = 0; row < _width; ++row)
	{
		for (int col = 0; col < _height; ++col)
		{
			rgb8 colors = image._bytes[row][col];
			_bytes[row][col] = (colors.r + colors.g + colors.b) / 3;
		}
	}	
}

ImagePGM::~ImagePGM() {
	free_bmatrix(_bytes, _nrl, _nrh, _ncl, _nch);
}

void ImagePGM::save(string path) {
	char cpath[path.size()];
	strcpy(cpath, path.c_str());
	SavePGM_bmatrix(_bytes, _nrl, _nrh, _ncl, _nch, cpath);
}


// Convolutions
ImagePGM& ImagePGM::lowPassFilter() {
	Matrix *matrix = Matrix::ones();
	return (*this)*(*matrix);
}

ImagePGM& ImagePGM::verticalGradient() {
	Matrix *matrix = Matrix::verticalSobel();
	return (*this)*(*matrix);
}

ImagePGM& ImagePGM::horizontalGradient() {
	Matrix *matrix = Matrix::horizontalSobel();
	return (*this)*(*matrix);
}

ImagePGM& ImagePGM::gradientNormal() {
	// TODO : Vérifier ce qu'il faut faire pour calculer la norme
	return (*this);
}


// Histogram
double* ImagePGM::histogram() {
	double *hist = new double[256];

	// Calcul de l'histogramme
	for (int row = 0; row < _width; ++row)
	{
		for (int col = 0; col < _height; ++col)
		{
			hist[_bytes[row][col]]++;
		}
	}

	// Somme cumulée de l'histogramme
	for (int i = 1; i < 256; ++i)
	{
		hist[i] = hist[i-1];
	}

	// Normalisation de l'histogramme
	int imageSize = _width * _height;
	for (int i = 0; i < 256; ++i)
	{
		hist[i] = hist[i] * 256 / imageSize;
	}

	return hist;
}


// Getter
byte** ImagePGM::bytes() {
	return _bytes;
}


// Operators
ImagePGM& ImagePGM::operator*(Matrix &matrix) {
	ImagePGM image(*this);

	int middleWidth = floor(matrix.width() / 2);
	int middleHeight = floor(matrix.height() / 2);

	for (int row = 0; row < _width; ++row)
	{
		for (int col = 0; col < _height; ++col)
		{
			
		}
	}

	return *this;
}

byte* ImagePGM::operator[](int i) {
	return _bytes[i];
}
