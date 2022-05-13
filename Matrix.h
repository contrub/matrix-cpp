#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

class Matrix {
    public:
        Matrix(int r, int c);

        explicit Matrix(std::vector<std::vector<double>>& matrix);

        int rows() const { return data.size(); };
        int cols() const { return data[0].size(); } ;

        Matrix& populateRandom();
        Matrix& transpose();

        double trace();

        double& operator()(int i, int j) const;

    protected:
        std::vector<std::vector<double>> mutable data;
};

Matrix operator + (const Matrix &a, const Matrix &b);
Matrix operator - (const Matrix &a, const Matrix &b);
Matrix operator * (double s, const Matrix &a);
Matrix operator * (const Matrix &a, const Matrix &b);
Matrix operator * (const Matrix &a, double s);

std::ostream& operator << (std::ostream& s, const Matrix &m);

#endif