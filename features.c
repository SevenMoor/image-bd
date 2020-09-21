#include <cstring>

#include "features.h"

int main(int argc, char const *argv[])
{
	long nrl, nrh, ncl, nch;

	char path[100] = IMAGE_PATH;
	strcat(path, "arbre1.pgm");
	byte **matrix = LoadPGM_bmatrix(path, &nrl, &nrh, &ncl, &nch);

	strcpy(path, IMAGE_PATH);
	strcat(path, "arbre1bis.pgm");
	SavePGM_bmatrix(matrix, nrl, nrh, ncl, nch, path);

	free_bmatrix(matrix, nrl, nrh, ncl, nch);

	return 0;
}