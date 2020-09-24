#include "ImagePGM.h"
#include "ImagePPM.h"
#include "Matrix.h"
#include "lib/nralloc.h"
#include "lib/nrio.h"

#include <cstring>
#include <cmath>

ImagePGM::ImagePGM() : Image() {
    _bytes = nullptr;
}

ImagePGM::ImagePGM(const string &filepath) : Image(filepath) {
	char cpath[filepath.size()];
	strcpy(cpath, filepath.c_str());
	_bytes = LoadPGM_bmatrix(cpath, &_nrl, &_nrh, &_ncl, &_nch);
	_width = (_nrh - _nrl) + 1;
	_height = (_nch - _ncl) + 1;
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
	return (*this)*(Matrix::ones());
}

ImagePGM& ImagePGM::sobel() {
	Matrix ix(_width, _height);
	Matrix iy(_width, _height);

	ix.setContent(_bytes);
    iy.setContent(_bytes);

	ix.horizontalGradient();
	iy.verticalGradient();

	for (int row = 0; row < _width; ++row)
	{
		for (int col = 0; col < _height; ++col)
		{
			_bytes[row][col] = sqrt(pow(ix[row][col], 2) + pow(iy[row][col], 2));
		}
	}

	return *this;
}

ImagePGM& ImagePGM::threshold(unsigned char i) {
	for (int row = 0; row < _width; ++row)
	{
		for (int col = 0; col < _height; ++col)
		{
            if(_bytes[row][col] < i) {
				_bytes[row][col] = 0;
			}
            else
            {
                _bytes[row][col] = 255;
            }
		}
	}
	return *this;
}


// Histogram
double* ImagePGM::histogram() {
	double *hist = new double[256]();

	// Calcul de l'histogramme
	for (int row = 0; row < _width; ++row)
	{
		for (int col = 0; col < _height; ++col)
		{
			hist[_bytes[row][col]]++;
		}
	}

//	// Somme cumulée de l'histogramme
//	for (int i = 1; i < 256; ++i)
//	{
//		hist[i] = hist[i-1];
//	}
//
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

	for (int row = middleWidth; row < _width - middleWidth; ++row)
	{
		for (int col = middleHeight; col < _height - middleHeight; ++col)
		{
			int sum = 0;
			// Itérer sur les pixels autour selon la taille du filtre
			for (int i = 0; i < matrix.width(); ++i)
			{
				for (int j = 0; j < matrix.height(); ++j)
				{
					// Multiplier les pixels par les coeficients du filtre
					sum += image[row - middleWidth + i][col - middleHeight + j] * matrix[i][j];
				}	
			}
			// Diviser par la somme des coefficents positifs de la matrice
			_bytes[row][col] = sum / matrix.coef();
		}
	}

	return *this;
}

byte* ImagePGM::operator[](int i) {
	return _bytes[i];
}
