#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <cmath>

template <typename T>
class MatrixBase {
public:
    MatrixBase();
    MatrixBase(size_t rows, size_t cols);

    void addElement(size_t row, size_t col, T value);
    T getElement(size_t row, size_t col) const;

    size_t getRows() const;
    size_t getCols() const;

    void Display() const;

protected:
    std::vector<std::vector<T>> data;
    size_t rows, cols;
};

template <typename T>
MatrixBase<T>::MatrixBase() : rows(1), cols(1) {
    data.resize(1, std::vector<T>(1, 0)); // initialisation a 0
}

// Constructeur avec spécification des dimensions
template <typename T>
MatrixBase<T>::MatrixBase(size_t _rows, size_t _cols) : rows(_rows), cols(_cols) {
    data.resize(_rows, std::vector<T>(_cols, 0)); // initialisation a 0
}

template <typename T>
void MatrixBase<T>::addElement(size_t row, size_t col, T value) {
    if (row < rows && col < cols) {
        data[row][col] = value;
    } else {
        std::cerr << "indice hors limites de la matrice" << std::endl;
    }
}

template <typename T>
T MatrixBase<T>::getElement(size_t row, size_t col) const {
    if (row < rows && col < cols) {
        return data[row][col];
    } else {
        std::cerr << "indice hors limites de la matrice" << std::endl;
        return T();
    }
}

template <typename T>
size_t MatrixBase<T>::getRows() const {
    return rows;
}

template <typename T>
size_t MatrixBase<T>::getCols() const {
    return cols;
}

template <typename T>
void MatrixBase<T>::Display() const {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            std::cout << std::setw(5) << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
//MATRIX NUMERICAL
template <typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    MatrixNumerical();
    MatrixNumerical(size_t rows, size_t cols);

    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const;
    MatrixNumerical<T> operator*(const T& scalar) const;
    MatrixNumerical<T> operator/(const T& scalar) const;

    T getDeterminant() const;
    MatrixNumerical<T> getInverse() const;

    static MatrixNumerical<T> getIdentity(size_t size);

private:
    MatrixNumerical<T> getCofactor(size_t p, size_t q) const;
};

template <typename T>
MatrixNumerical<T>::MatrixNumerical() : MatrixBase<T>() {}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(size_t rows, size_t cols) : MatrixBase<T>(rows, cols) {}

// +
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T>& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Dimensions incompatibles pour l'addition");
    }
    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// -
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T>& other) const {
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Dimensions incompatibles pour la soustraction");
    }
    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            result.data[i][j] = this->data[i][j] - other.data[i][j];
        }
    }
    return result;
}

// .
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const T& scalar) const {
    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            result.data[i][j] = this->data[i][j] * scalar;
        }
    }
    return result;
}

// /
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator/(const T& scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Division par zéro");
    }
    MatrixNumerical<T> result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            result.data[i][j] = this->data[i][j] / scalar;
        }
    }
    return result;
}

// det
template <typename T>
T MatrixNumerical<T>::getDeterminant() const {
    //finir
    return T(); 
}

// Mat inverse
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const {
    //finir
    return MatrixNumerical<T>();
}

// Mat Id
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(size_t size) {
    MatrixNumerical<T> identity(size, size);
    for (size_t i = 0; i < size; i++) {
        identity.addElement(i, i, 1);
    }
    return identity;
}

// cofacteur 
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getCofactor(size_t p, size_t q) const {
    MatrixNumerical<T> cofactor(this->rows - 1, this->cols - 1);
    size_t i_cofactor = 0, j_cofactor = 0;
    for (size_t i = 0; i < this->rows; i++) {
        if (i == p) continue; // Sauter la ligne
        j_cofactor = 0;
        for (size_t j = 0; j < this->cols; j++) {
            if (j == q) continue; // Sauter la colonne
            cofactor.addElement(i_cofactor, j_cofactor, this->data[i][j]);
            j_cofactor++;
        }
        i_cofactor++;
    }
    return cofactor;//àverifier
}

//teste
int main() {
    MatrixNumerical<int> mat1(3, 3);
    
    mat1.addElement(0, 0, 1);
    mat1.addElement(0, 1, 2);
    mat1.addElement(0, 2, 3);
    mat1.addElement(1, 0, 4);
    mat1.addElement(1, 1, 5);
    mat1.addElement(1, 2, 6);
    mat1.addElement(2, 0, 7);
    mat1.addElement(2, 1, 8);
    mat1.addElement(2, 2, 9);

    std::cout << "Matrice 1:" << std::endl;
    mat1.Display();

    MatrixNumerical<int> mat2(3, 3);
    mat2.addElement(0, 0, 9);
    mat2.addElement(0, 1, 8);
    mat2.addElement(0, 2, 7);
    mat2.addElement(1, 0, 6);
    mat2.addElement(1, 1, 5);
    mat2.addElement(1, 2, 4);
    mat2.addElement(2, 0, 3);
    mat2.addElement(2, 1, 2);
    mat2.addElement(2, 2, 1);

    std::cout << "Matrice 2:" << std::endl;
    mat2.Display();

    MatrixNumerical<int> result1 = mat1 + mat2;

    std::cout << "Matrice 1 + Matrice 2:" << std::endl;
    result1.Display();
    
    MatrixNumerical<int> result2 = mat1 - mat2;

    std::cout << "Matrice 1 - Matrice 2:" << std::endl;
    result2.Display();
    
    MatrixNumerical<int> result3 = mat1*3;

    std::cout << "Matrice 1 *3:" << std::endl;
    result3.Display();
    
    MatrixNumerical<int> result4 = mat1 /3;

    std::cout << "Matrice 1 / 3:" << std::endl;
    result4.Display();

    return 0;
}

#endif
