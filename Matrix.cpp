#include "Matrix.h"

int Matrix::height(){
    return _height;
}

int Matrix::width(){
    return _width;
}

int** Matrix::content(){
    return _content;
}

void Matrix::setContent(int** content){
    _content = content;
}

int* Matrix::operator[](int i){
    return *_content;
}

Matrix::Matrix(int width, int height) : _width(width), _height(height) {
    _content = (int**) malloc(width*height*sizeof(int));
}

Matrix* Matrix::verticalSobel(){
    int** tmp = (int**) malloc(3*3*sizeof(int));
    tmp[0][0] = -1;
    tmp[0][1] = 0;
    tmp[0][2] = 1;
    tmp[1][0] = -2;
    tmp[1][1] = 0;
    tmp[1][2] = 2;
    tmp[2][0] = -1;
    tmp[2][1] = 0;
    tmp[2][2] = 1;
    Matrix* m = new Matrix(3,3);
    m->setContent(tmp);
    return m;
}

Matrix* Matrix::horizontalSobel(){
    int** tmp = (int**) malloc(3*3*sizeof(int));
    tmp[0][0] = -1;
    tmp[0][1] = -2;
    tmp[0][2] = -1;
    tmp[1][0] = 0;
    tmp[1][1] = 0;
    tmp[1][2] = 0;
    tmp[2][0] = 1;
    tmp[2][1] = 2;
    tmp[2][2] = 1;
    Matrix* m = new Matrix(3,3);
    m->setContent(tmp);
    return m;
}

Matrix::~Matrix(){
    free(_content);
}

Matrix* Matrix::ones(){
    int** tmp = (int**) malloc(3*3*sizeof(int));
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            tmp[i][j] = 1;
        }
    }
    Matrix* m = new Matrix(3,3);
    m->setContent(tmp);
    return m;
}