#include "FileExporter.h"
 #include "ImagePGM.h"
 #include "DBFacade.h"
 #include "ImagePPM.h"

#include <iostream>
#include <dirent.h>
#include <sys/types.h>

using namespace std;

int main(int argc, char const *argv[]){
	FileExporter fileExporter("data");

	struct dirent *entry;
   	DIR *dir = opendir("feed/archivePPMPGM/archive500pgm");
	while ((entry = readdir(dir)) != NULL){
			if(entry->d_name!="."||entry->d_name!=".."){
				ImagePGM image(entry->d_name);
				fileExporter.add(entry->d_name,DBFacade::getGradientAverage(image),DBFacade::getContourPointRate(image),DBFacade::getHistogram(image));
			}
	}
   closedir(dir);

	return 0;
}