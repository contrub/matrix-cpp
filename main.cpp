#include <iostream>

#include "Matrix.h"

using namespace std;

int main() {
    const int n = 7;
    Matrix m1(5, 5);
    Matrix m2(5, 5);

    m1.populateRandom();
    m2.populateRandom();

    cout << m1 << endl;
    cout << m2 << endl;

    cout << m1.transpose() << endl;

    cout << m1 + m2 << endl;
    cout << m2 - m1 << endl;
    cout << n * m1 << endl;

    cout << m1(3, 4) << endl;

    return 0;
}
