#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool checkFileExistence(const string& filename) {
    ifstream f(filename.c_str());

    return f.is_open();
}

void getFile(string filename, ifstream& file) {
    const bool file_exists = checkFileExistence(filename);

    if (!file_exists) {
        cout << "File " << filename << " not found." << endl;

        exit(0);
    }

    file.open(filename.c_str());
}
