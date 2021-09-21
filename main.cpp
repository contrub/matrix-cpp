#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "file.cpp"
#include "matrix.cpp"

using namespace std;

const string filename1 = "input1.txt";
const string filename2   = "input2.txt";

void output_matrix(vector<vector<double>> matrix) {
    for (int i=0; i < matrix.size(); i++) {
        for (int j=0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {
    ifstream file1, file2;

    getFile(filename1, file1);
    getFile(filename2, file2);

    string line;

    vector<vector<double>> matrix1;
    vector<vector<double>> matrix2;

    double value;

    while (getline(file1, line)) {
        vector<double> row;
        istringstream iss(line);

        while (iss >> value) {
            row.push_back(value);
        }

        matrix1.push_back(row);
    }

    while (getline(file2, line)) {
        vector<double> row;
        istringstream iss(line);

        while (iss >> value) {
            row.push_back(value);
        }

        matrix2.push_back(row);
    }

    // vector<vector<double>> test = sum_matrices(matrix1, matrix2);                // сложение матриц
    // vector<vector<double>> test = subtraction_matrices(matrix1, matrix2);        // вычитание матриц
    // vector<vector<double>> test = multiplication_matrix_by_number(matrix1, 0);   // умножение матрицы на число
    // vector<vector<double>> test = transpose_matrix(matrix1);                     // транспонирование матрицы

    // output_matrix(test);

    file1.close();
    file2.close();

    return 0;
}
