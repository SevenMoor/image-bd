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
   	DIR *dir = opendir("feed/archivePPMPGM/archive500ppm");
	while ((entry = readdir(dir)) != NULL){
			string name(entry->d_name);
			if(name!="."&&name!=".."){
				cout << "Treated " << name << endl;
				ImagePPM image("feed/archivePPMPGM/archive500ppm/"+name);
				fileExporter.add(name,DBFacade::getGradientAverage(image),DBFacade::getContourPointRate(image),DBFacade::getHistogram(image));
			}
	}
	fileExporter.save();
   closedir(dir);

	return 0;
}