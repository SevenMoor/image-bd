#ifndef  MATRIX_H
#define MATRIX_H

#include <cstdlib>
#include "lib/def.h"

class Matrix{
    private:
        static Matrix _verticalSobel;
        static Matrix _horizontalSobel;
        static Matrix _ones;
        int _width;
        int _height;
        int _coef;
        int** _content;

        void updateCoef();

    public:
        static Matrix& verticalSobel();
        static Matrix& horizontalSobel();
        static Matrix& ones();

        Matrix(int width, int height);
        Matrix(const Matrix& matrix);
        ~Matrix();

        Matrix& horizontalGradient();
        Matrix& verticalGradient();

        int** content();
        void setContent(int** content);
        void setContent(byte** content);
        int height() const;
        int width() const;
        int coef() const;

        Matrix& operator*(Matrix &matrix);
        int* operator[](int i);
};

#endif