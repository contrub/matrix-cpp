#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <algorithm>
#include <memory>

#include "Matrix.h"

Matrix::Matrix(int r, int c) {
    assert(r >= 0 && c >= 0);

    data.resize(r);

    for (int i = 0; i < r; i++) {
        data[i].resize(c);
    }
}

Matrix::Matrix(std::vector<std::vector<double>>& matrix) {
    assert(!matrix.empty() && !matrix[0].empty());

    for (int i = 0; i < matrix.size() - 1; i++) {
        assert(matrix[i].size() == matrix[i].size());
    }

    data.resize(matrix.size());

    for (int i = 0; i < matrix.size(); i++) {
        data[i].resize(matrix[i].size());
        for (int j = 0; j < matrix[i].size(); j++) {
            data[i][j] = matrix[i][j];
        }
    }
}

Matrix& Matrix::populateRandom() {
    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols(); j++) {
            data[i][j] = rand() % 10;
        }
    }

    return *this;
}

Matrix operator + (const Matrix &a, const Matrix &b){
    assert(a.cols() == b.cols() && a.rows() == b.rows());

    std::shared_ptr<Matrix> c(new Matrix(a.rows(),a.cols()));

    for (int i = 0; i < a.rows(); i++) {
        for (int j=0;j<a.cols();j++) {
            (*c)(i, j) = a(i, j) + b(i, j);
        }
    }

    return *c;
}

Matrix operator - (const Matrix &a, const Matrix &b){
    assert(a.cols() == b.cols() && a.rows() == b.rows());

    std::shared_ptr<Matrix> c(new Matrix(a.rows(), a.cols()));

    for (int i = 0; i < a.rows(); i++) {
        for (int j = 0; j < a.cols(); j++) {
            (*c)(i, j) = a(i, j) - b(i, j);
        }
    }

    return *c;
}

Matrix operator * (const Matrix &a, const Matrix &b){
    assert(a.cols() == b.rows());

    std::shared_ptr<Matrix> c(new Matrix(a.rows(), a.cols()));

    for (int i = 0; i < a.rows(); i++) {
        for (int j = 0; j < a.rows(); j++) {
            for (int k = 0; k < a.rows(); k++) {
                (*c)(i, j) = a(i, k) * b(k, j);
            }
        }
    }

    return *c;
}

Matrix operator * (const double s, const Matrix &a) {
    std::shared_ptr<Matrix> b(new Matrix(a.rows(), a.cols()));

    for (int i = 0; i < a.rows(); i++) {
        for (int j = 0; j < a.cols(); j++) {
            (*b)(i, j) = s * a(i, j);
        }
    }
    return *b;
}

Matrix operator * (const Matrix &a, const double s) {
    return s * a;
}

double& Matrix::operator () (int i, int j) const {
    return data[i][j];
}

std::ostream& operator << (std::ostream& s, const Matrix &m) {
    for (int i = 0; i < m.rows(); i++) {
        for (int j = 0; j < m.cols(); j++) {
            s << " " << m(i, j) << " ";
        }
        s << std::endl;
    }

    return s;
}

Matrix& Matrix::transpose() {
    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols(); j++) {
            (*this)(j, i) = data[i][j];
        }
    }
    return *this;
}

double Matrix::trace() {
    assert(rows() == cols());

    double sum = 0;

    for (int i = 0; i < rows(); i++) {
        sum += (*this)(i, i);
    }

    return sum;
}