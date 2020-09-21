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
        int read(int i, int j);
        static Matrix sobel();
        static Matrix ones();
};

#endif