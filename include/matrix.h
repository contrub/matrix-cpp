#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H

#include <iostream>
#include <vector>

class Matrix {
    public:
        /** Creates a zero matrix of the given size */
        Matrix(int r, int c);

        /** Returns the number of rows in the matrix */
        int rows() const;

        /** Returns the number of columns in the matrix */
        int cols() const;

        /** Generate matrix with random integers in the range [0:9] */
        Matrix& populateRandom();

        /** Returns transpose object Matrix of the current Matrix*/
        Matrix transpose();

        /** Returns trace of the Matrix */
        double trace();

        /** Method that allows you to access the elements in the matrix using subscripts */
        double& operator()(int i, int j) const;

    protected:
        /** Matrix storage  */
        std::vector<std::vector<double> > mutable data;
};

static const Matrix NullMatrix(0,0);

/** Adds two Matrix */
Matrix operator + (const Matrix &a, const Matrix &b);

/** Subtracts the second matrix from the first matrix */
Matrix operator - (const Matrix &a, const Matrix &b);

/** Multiplies Matrix by a scalar (double) */
Matrix operator * (const double s, const Matrix &a);

/** Multiplies a Matrix by a scalar (double) */
Matrix operator * (const Matrix &a, const double s);

/** Prints out a Matrix object */
std::ostream& operator << (std::ostream& s, const Matrix &m);

#endif