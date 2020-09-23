#include <cstring>

#include "features.h"
#include "ImagePGM.h"

int main(int argc, char const *argv[])
{
	string imageName("arbre1");

	// Charger une image
	ImagePGM imagePGM(std::string(IMAGE_PATH) + imageName + ".pgm");
	imagePGM.save("results/" + imageName + "_0.pgm");

	// Filtre passe bas
	imagePGM.lowPassFilter();
	imagePGM.save("results/" + imageName + "_1_lowpass.pgm");

	// Norme de sobel
	ImagePGM imagePGM_sobel(imagePGM);
	imagePGM_sobel.sobel();
	imagePGM_sobel.save("results/" + imageName + "_2_sobel.pgm");

	// Seuillage
	ImagePGM imagePGM_threshold(imagePGM_sobel);
	imagePGM_threshold.threshold(15);
	imagePGM_threshold.save("results/" + imageName + "_3_threshold.pgm");

	// Histogramme
	double *histo = imagePGM.histogram();
    for (int i = 0; i < 256; ++i)
    {
        std::cout << histo[i] << " ";
    }
    std::cout << std::endl;

	return 0;
}