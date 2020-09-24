#include <cmath>
#include <iostream>
#include "Matrix.h"

Matrix Matrix::_verticalSobel(3, 3);
Matrix Matrix::_horizontalSobel(3, 3);
Matrix Matrix::_ones(3, 3);

static Matrix& verticalSobel();
static Matrix& horizontalSobel();
static Matrix& ones();

Matrix::Matrix(int width, int height) : _width(width), _height(height) {
    _coef = 0;
    _content = nullptr;
}

Matrix::Matrix(const Matrix& matrix) {
    _width = matrix._width;
    _height = matrix._height;
    _coef = matrix._coef;
    _content = new int*[_width]();
    for (int row = 0; row < _width; ++row)
    {
        _content[row] = new int[_height]();
        for (int col = 0; col < _height; ++col)
        {
            _content[row][col] = matrix._content[row][col];
        }
    }
}

Matrix::~Matrix(){
    if (_content != nullptr)
    {
        for (int i = 0; i < _width; ++i)
        {
            delete[] _content[i];
        }
        delete[] _content;
    }
}

void Matrix::updateCoef()
{
    for (int i = 0; i < _width; ++i)
    {
        for (int j = 0; j < _height; ++j)
        {
            if(_content[i][j] > 0) {
                _coef += _content[i][j];
            }
        }
    }
}

int** Matrix::content(){
    return _content;
}

Matrix& Matrix::ones() {
    if(_ones._content == nullptr) {
        int **ones = new int*[3];
        ones[0] = new int[3]; ones[1] = new int[3]; ones[2] = new int[3];
        ones[0][0] = 1; ones[1][0] = 1; ones[2][0] = 1;
        ones[0][1] = 1; ones[1][1] = 1; ones[2][1] = 1;
        ones[0][2] = 1; ones[1][2] = 1; ones[2][2] = 1;
        _ones._content = ones;
        _ones._coef = 9;
    }

    return _ones;
}

Matrix& Matrix::horizontalSobel(){
    if(_horizontalSobel._content == nullptr) {
        int **sobel = new int*[3];
        sobel[0] = new int[3]; sobel[1] = new int[3]; sobel[2] = new int[3];
        sobel[0][0] = -1; sobel[1][0] = 0; sobel[2][0] = 1;
        sobel[0][1] = -2; sobel[1][1] = 0; sobel[2][1] = 2;
        sobel[0][2] = -1; sobel[1][2] = 0; sobel[2][2] = 1;
        _horizontalSobel._content = sobel;
        _horizontalSobel._coef = 4;
    }

    return _horizontalSobel;
}

Matrix& Matrix::verticalSobel() {
    if(_verticalSobel._content == nullptr) {
        int **sobel = new int*[3];
        sobel[0] = new int[3]; sobel[1] = new int[3]; sobel[2] = new int[3];
        sobel[0][0] = -1; sobel[1][0] = -2; sobel[2][0] = -1;
        sobel[0][1] =  0; sobel[1][1] =  0; sobel[2][1] =  0;
        sobel[0][2] =  1; sobel[1][2] =  2; sobel[2][2] =  1;
        _verticalSobel._content = sobel;
        _verticalSobel._coef = 4;
    }

    return _verticalSobel;
}

Matrix& Matrix::horizontalGradient() {
    return (*this)*(Matrix::horizontalSobel());
}

Matrix& Matrix::verticalGradient() {
    return (*this)*(Matrix::verticalSobel());
}

int Matrix::height() const {
    return _height;
}

int Matrix::width() const {
    return _width;
}
int Matrix::coef() const {
    return _coef;
}

void Matrix::setContent(byte **imageMatrix)
{
    if (_content == nullptr) {
        _content = new int*[_width];
        for (int row = 0; row < _width; ++row)
        {
            _content[row] = new int[_height]();
        }
    }

    for (int row = 0; row < _width; ++row)
    {
        for (int col = 0; col < _height; ++col)
        {
            _content[row][col] = imageMatrix[row][col];
        }
    }
}

void Matrix::setContent(int** content){
    _content = content;
    updateCoef();
}

// Operators
Matrix& Matrix::operator*(Matrix &matrix) {
    Matrix computeMatrix(*this);

    int middleWidth = floor(matrix.width() / 2.0);
    int middleHeight = floor(matrix.height() / 2.0);

    for (int row = 0; row < _width; ++row)
    {
        for (int col = 0; col < _height; ++col)
        {
            int sum = 0;
            // Itérer sur les pixels autour selon la taille du filtre
            for (int i = 0; i < matrix.width(); ++i)
            {
                for (int j = 0; j < matrix.height(); ++j)
                {
                    // Éviter les effets de bord
                    if((row - middleWidth + i < 0) || (row - middleWidth + i >= _width) || (col - middleHeight + j < 0) || (col - middleHeight + j >= _height)) continue;

                    // Multiplier les pixels par les coeficients du filtre
                    sum += computeMatrix[row - middleWidth + i][col - middleHeight + j] * matrix[i][j];
                }
            }
            // Diviser par la somme des coefficents positifs de la matrice
            _content[row][col] = sum / matrix.coef();
        }
    }

    return *this;
}
int* Matrix::operator[](int i){
    return _content[i];
}
