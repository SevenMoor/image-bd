#ifndef  DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include <occi.h>

using namespace oracle::occi;
using namespace std;

class DatabaseConnector{
    private:
        static Environment* env;
        static Connection* c;
    public:
        static void init(string host, string user, string pass, string database);
        static void insert(string nom, float gradientAverage, float contourPointRate,double** histogram);
        static void insert(string nom, float gradientAverage, float contourPointRate,double* histogram);
        string* selectSimilar(string file); 
};

#endif