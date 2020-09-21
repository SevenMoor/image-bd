#ifndef  MATRIX_H
#define MATRIX_H

#include <cstdlib>

class Matrix{
    private:
        int _width;
        int _height;
        int** _content;

    public:
        static Matrix* verticalSobel();
        static Matrix* horizontalSobel();
        static Matrix* ones();

        Matrix(int width, int height);
        ~Matrix();

        int** content();
        void setContent(int** content);
        int height() const;
        int width() const;

        int* operator[](int i);        
};

#endif