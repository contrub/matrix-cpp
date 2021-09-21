#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> sum_matrices(vector<vector<double>> &matrix1, vector<vector<double>> &matrix2) {
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
        cout << "The number of rows and columns must be equal to sum matrices";

        exit(0);
    }

    vector<vector<double>> matrix;

    for (int i=0; i < matrix1.size(); i++) {
        matrix.push_back(vector<double>());

        for (int j=0; j < matrix1[0].size(); j++) {
            matrix[i].push_back(matrix1[i][j] + matrix2[i][j]);
        }
    }

    return matrix;
}

vector<vector<double>> subtraction_matrices(vector<vector<double>> &matrix1, vector<vector<double>> &matrix2) {
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
        cout << "The number of rows and columns must be equal to sum matrices";

        exit(0);
    }

    vector<vector<double>> matrix;

    for (int i=0; i < matrix1.size(); i++) {
        matrix.push_back(vector<double>());

        for (int j=0; j < matrix1[0].size(); j++) {
            matrix[i].push_back(matrix1[i][j] - matrix2[i][j]);
        }
    }

    return matrix;
}

vector<vector<double>> multiplication_matrix_by_number(vector<vector<double>> &matrix0, double number) {
    vector<vector<double>> matrix;

    for (int i=0; i < matrix0.size(); i++) {
        matrix.push_back(vector<double>());

        for (int j=0; j < matrix0[0].size(); j++) {
            matrix[i].push_back(matrix0[i][j] * number);
        }
    }

    return matrix;
}

vector<vector<double>> transpose_matrix(vector<vector<double>> matrix0) {
    vector<vector<double>> matrix;

    for (int i=0; i < matrix0[0].size(); i++) {
        matrix.push_back(vector<double>());

        for (int j=0; j < matrix0.size(); j++) {
            matrix[i].push_back(matrix0[j][i]);
        }
    }

    return matrix;
}
