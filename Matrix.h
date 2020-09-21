#ifndef  MATRIX_H
#define MATRIX_H

class Matrix{
    private:
        int _height;
        int _width;
        int** _content;
        Matrix(int width, int height);
    public:
        int height();
        int width();
        int** content();
        int* operator[](int i);
        static Matrix verticalSobel();
        static Matrix horizontalSobel();
        static Matrix ones();
};

#endif