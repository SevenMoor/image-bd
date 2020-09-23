#include "FileExporter.h"

#include <fstream>

FileExporter::FileExporter(string filename) : _filename(filename), _lines(new vector<string>()) {}


void FileExporter::add(string nom, float gradientAverage, float contourPointRate,double** histogram){
    string histString = "histogram_RGB(";
    for(int i=0; i<3; i++){
        histString += "histogram(";

        for(int j=0; j<256; j++){
            histString += to_string(histogram[i][j]);
            if(j!=255)
                histString += ",";
        }

        histString += ")";
        if(i!=2)
            histString += ",";
    }

    histString +=")";
    _lines->push_back(nom+"::color::"+to_string(gradientAverage)+"::"+to_string(contourPointRate)+"::"+histString);
}


void FileExporter::add(string nom, float gradientAverage, float contourPointRate,double*   histogram){
    string histString = "histogram(";

    for(int j=0; j<256; j++){
        histString += to_string(histogram[j]);
        if(j!=255)
            histString += ",";
    }

    histString += ")";
    _lines->push_back(nom+"::gray::"+to_string(gradientAverage)+"::"+to_string(contourPointRate)+"::"+histString);
}


void FileExporter::save(){
    ofstream dump;
    dump.open (_filename);
    for(int i=0; i<_lines->size();i++)
        dump << _lines->at(i) << endl;
    dump.close();
}

FileExporter::~FileExporter(){
    delete _lines;
}