#include <iostream>

#include "../include/matrix.h"

using namespace std;

int main() {
    Matrix m1(5, 5);
    Matrix m2(5, 5);

    m1.populateRandom();
    m2.populateRandom();

    cout << m1;
    cout << m2;

    cout << m1.trace() << endl;
    cout << m1.transpose();

    return 0;
}
