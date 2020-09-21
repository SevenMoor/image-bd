#ifndef  MATRIX_H
#define MATRIX_H

#include <cstdlib>

class Matrix{
    private:
        int _height;
        int _width;
        int** _content;
    public:
        Matrix(int width, int height);
        void Matrix::setContent(int** content);
        ~Matrix();
        int height();
        int width();
        int** content();
        int* operator[](int i);
        static Matrix* verticalSobel();
        static Matrix* horizontalSobel();
        static Matrix* ones();
};

#endif