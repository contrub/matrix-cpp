#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

#include "matrix.h"

using namespace std;

Matrix::Matrix(int r, int c) {
    assert(r >= 0 && c >= 0);

    data.resize(r);

    for (int i = 0; i < r; i++) {
        data[i].resize(c);
    }
}


int Matrix::rows() const {
    return data.size();
}

int Matrix::cols() const {
    if (rows() == 0) return 0;

    return data[0].size();
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

    shared_ptr<Matrix> c(new Matrix(a.rows(),a.cols()));

    for (int i = 0; i < a.rows(); i++) {
        for (int j=0;j<a.cols();j++) {
            (*c)(i, j) = a(i, j) + b(i, j);
        }
    }

    return *c;
}

Matrix operator - (const Matrix &a, const Matrix &b){
    assert(a.cols() == b.cols() && a.rows() == b.rows());

    shared_ptr<Matrix> c(new Matrix(a.rows(), a.cols()));

    for (int i = 0; i < a.rows(); i++) {
        for (int j = 0; j < a.cols(); j++) {
            (*c)(i, j) = a(i, j) - b(i, j);
        }
    }

    return *c;
}

Matrix operator * (const double s, const Matrix &a) {
    shared_ptr<Matrix> b(new Matrix(a.rows(), a.cols()));

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

ostream& operator << (ostream& s, const Matrix &m) {
    s << "[ " << endl;

    for (int i = 0; i < m.rows(); i++) {
        s << "\t" << "[";
        for (int j = 0; j < m.cols(); j++) {
            s << " " << m(i,j) << " ";
        }
        s << "]" << endl;
    }
    s << "]" << endl;

    return s;
}

Matrix Matrix::transpose() {
    shared_ptr<Matrix> c(new Matrix(cols(),rows()));

    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols(); j++) {
            (*c)(j, i) = data[i][j];
        }
    }
    return *c;
}

double Matrix::trace() {
    assert(rows() == cols());

    double sum = 0;

    for (int i = 0; i < rows(); i++) {
        sum += (*this)(i, i);
    }

    return sum;
}