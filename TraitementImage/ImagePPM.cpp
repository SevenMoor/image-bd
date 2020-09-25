#include "ImagePPM.h"
#include "ImagePGM.h"
#include "lib/nralloc.h"
#include "lib/nrio.h"

#include <cstring>

ImagePPM::ImagePPM() : Image() {}

ImagePPM::ImagePPM(string filepath) : Image(filepath) {
	char cpath[filepath.size()];
	strcpy(cpath, filepath.c_str());
	_bytes = LoadPPM_rgb8matrix(cpath, &_nrl, &_nrh, &_ncl, &_nch);
	_width = (_nrh - _nrl) + 1;
	_height = (_nch - _ncl) + 1;
}

ImagePPM::ImagePPM(const ImagePPM& image) : Image(image) {
	_bytes = rgb8matrix(_nrl, _nrh, _ncl, _nch);

	for (int row = 0; row < _width; ++row)
	{
		for (int col = 0; col < _height; ++col)
		{
			_bytes[row][col] = image._bytes[row][col];
		}
	}
}

ImagePPM::ImagePPM(const ImagePGM& image) : Image(image) {
	_bytes = rgb8matrix(_nrl, _nrh, _ncl, _nch);

	for (int row = 0; row < _width; ++row)
	{
		for (int col = 0; col < _height; ++col)
		{
			_bytes[row][col].r = image._bytes[row][col];
			_bytes[row][col].g = image._bytes[row][col];
			_bytes[row][col].b = image._bytes[row][col];
		}
	}
}

ImagePPM::~ImagePPM() {
	free_rgb8matrix(_bytes, _nrl, _nrh, _ncl, _nch);
}

void ImagePPM::save(string path) {
	char cpath[path.size()];
	strcpy(cpath, path.c_str());
	SavePPM_rgb8matrix(_bytes, _nrl, _nrh, _ncl, _nch, cpath);
}

double** ImagePPM::histogram() {
	double **hist = new double*[3];

	for (int i = 0; i < 3; ++i)
	{
		hist[i] = new double[256]();
	}

	// Calcul de l'histogramme
	for (int row = 0; row < _width; ++row)
	{
		for (int col = 0; col < _height; ++col)
		{
			byte color[3] = {_bytes[row][col].r, _bytes[row][col].g, _bytes[row][col].b};

			hist[0][color[0]]++; 
			hist[1][color[1]]++;
			hist[2][color[2]]++;
		}
	}
	
	// Normalisation de l'histogramme
	int imageSize = _width * _height;
	for (int i = 0; i < 256; ++i)
	{
		hist[0][i] = hist[0][i] / imageSize;
		hist[1][i] = hist[1][i] / imageSize;
		hist[2][i] = hist[2][i] / imageSize;
	}

	return hist;
}

rgb8** ImagePPM::bytes() {
	return _bytes;
}