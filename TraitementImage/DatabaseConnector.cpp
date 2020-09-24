#include "DatabaseConnector.h"

void DatabaseConnector::init(string host, string user, string pass, string database){
    _env = Environment::createEnvironment();
    _c = _env->createConnection("Y2020M2_PAUQUET","M123456M","Code:ucp=(DESCRIPTION =(ADDRESS=(PROTOCOL = TCP)(HOST = 10.40.128.30)(PORT = 1521))(CONNECT_DATA= (SID = orcl)(SERVER = DEDICATED)))");
}


void DatabaseConnector::insert(string nom, float gradientAverage, float contourPointRate,double** histogram){

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

    Statement* s = _c->createStatement("UPDATE multimedia"
                                                                        "SET"
                                                                            "grad="+to_string(gradientAverage)+
                                                                            "contour_point="+to_string(contourPointRate)+
                                                                            "hist_rgb="+histString+
                                                                            "WHERE nom="+nom);
    s->executeQuery();
}


void DatabaseConnector::insert(string nom, float gradientAverage, float contourPointRate,double* histogram){
    string histString = "histogram(";

        for(int j=0; j<256; j++){
            histString += to_string(histogram[j]);
            if(j!=255)
                histString += ",";
        }

        histString += ")";

    Statement* s = _c->createStatement("UPDATE multimedia"
                                                                        "SET"
                                                                            "grad="+to_string(gradientAverage)+
                                                                            "contour_point="+to_string(contourPointRate)+
                                                                            "hist="+histString+
                                                                            "WHERE nom="+nom);
    s->executeQuery();
}


string* DatabaseConnector::selectSimilar(string file){
    //TODO
}


void DatabaseConnector::close(){
    _env->terminateConnection(_c);
    Environment::terminateEnvironment(_env);
}