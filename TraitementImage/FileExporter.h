#ifndef  FILEEXPORTER_H
#define FILEXPORTER_H

#include <string>
#include <vector>

using namespace std;

class FileExporter{
private:
    string _filename;
    vector<string>* _lines;
public:
    FileExporter(string filename);
    void add(string nom, float gradientAverage, float contourPointRate,double** histogram);
    void add(string nom, float gradientAverage, float contourPointRate,double*   histogram);
    void save();
    ~FileExporter();
};

#endif