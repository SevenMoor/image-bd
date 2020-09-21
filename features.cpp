#include <cstring>

#include "features.h"

int main(int argc, char const *argv[])
{
	long nrl, nrh, ncl, nch;

	// std::cout << "Chargement de l'image" << std::endl;

	char path[100] = IMAGE_PATH;
	strcat(path, "arbre1.pgm");
	byte **matrix = LoadPGM_bmatrix(path, &nrl, &nrh, &ncl, &nch);

	// std::cout << "Sauvegarde de la copie de l'image" << std::endl;
	strcpy(path, "arbre1bis.pgm");
	SavePGM_bmatrix(matrix, nrl, nrh, ncl, nch, path);

	// std::cout << "Libération des matrices" << std::endl;
	free_bmatrix(matrix, nrl, nrh, ncl, nch);

	return 0;
}