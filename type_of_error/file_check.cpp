#include <iostream>
#include <exception>
#include <fstream> 
#include <vector>

using namespace std;

class Matrix2x2 {
    private:
        int data[2][2];
    public:
        Matrix2x2();
        void loadFromFile(const string& path);
        void saveToFile(const string& path) const;
};

Matrix2x2::Matrix2x2() {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            data[i][j] = 0;
        }
    }
}

void Matrix2x2::loadFromFile(const string& path) {
    ifstream file;

    try {
        file.open(path);

        if (!file.is_open()) {
            cout << "File not found at: " << path << endl;
            throw runtime_error("file not found");
        }

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                file >> data[i][j];  
                if (file.fail()) {
                    throw runtime_error("Failed to read matrix value");
                } 
            }
        }

        file.close();
    }
    catch (const exception& e) {
        throw;
    }
}

void Matrix2x2::saveToFile(const string& path) const {
    ofstream file;

    try {
        file.open(path);

    if(!file.is_open()) {
        cout << "No rights to write to file: " << path << endl;
        throw runtime_error("cannot write file");
        }

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                file << data[i][j];
                if (j < 1) file << " ";
            }
            file << "\n";
        }

        file.close();
    }
    catch (const exception& e) {
        throw;
    }
}

int main () {
    Matrix2x2 m;

    try {
        cout << "=== TRY #1: loadFromFile() ===\n";
        m.loadFromFile("file_that_does_not_exist.txt");
        cout << "Loaded matrix successfully.\n";
    }
    catch (const exception& e) {
        cout << "Caught exception (load): " << e.what() << endl;
    }

    try {
        cout << "\n=== TRY #2: saveToFile() ===\n";

        m.saveToFile("C:\\Windows\\system32\\matrix.txt");
    }
    catch (const exception& e) {
            cout << "Caught exception (save): " << e.what() << endl;
    }

    return 0;
}