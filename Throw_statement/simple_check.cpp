#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class IndexOutOfRange : public runtime_error {
    public:
        IndexOutOfRange(const string& msg) : runtime_error(msg) {}
};

class MatrixException : public runtime_error {
    public:
        MatrixException(const string& msg) : runtime_error(msg) {}
};

class Matrix {
    private:
        int rows;
        int cols;

        vector<vector<int>> data;
    public:
        Matrix() {
            rows = 0;
            cols = 0;
            data = {};
        }

        Matrix(int rows, int cols) {
            if (rows <= 0 || cols <= 0)
            throw invalid_argument("invalid_argument");

            this->rows = rows;
            this->cols = cols;
            data.assign(rows, vector<int>(cols, 0));
        }

        void setValue(int r, int c, int value);
        int getValue(int r, int c) const;
        void fillWith(int value);

        Matrix operator+(const Matrix& other) const;
        void addInPlace(const Matrix& other);

        bool isEmpty() const;
        void assertSameSizeOrThrow(const Matrix& other) const;
        friend ostream& operator<<(ostream& os, const Matrix& m);
};

void Matrix::setValue(int r, int c, int value){
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        throw IndexOutOfRange("Index out of range");

    data[r][c] = value;
};

int Matrix::getValue(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        throw IndexOutOfRange("Index out of range");

    return data[r][c];
};

void Matrix::fillWith(int value) {
    if (isEmpty()) throw invalid_argument("Matrix is empty");
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] = value;
}

void Matrix::addInPlace(const Matrix& other) {
    assertSameSizeOrThrow(other);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] += other.data[i][j];
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result = *this;
    result.addInPlace(other);
    return result;
}

bool Matrix::isEmpty() const{
    return rows == 0 || cols == 0;
}

void Matrix::assertSameSizeOrThrow(const Matrix& other) const {
    if(this->rows != other.rows || this->cols != other.cols) 
        throw MatrixException("Matrices don't fit.");
}

ostream& operator<<(ostream& os, const Matrix& m) {
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j)
            os << m.data[i][j] << " ";
        os << "\n";
    }
    return os;
}

int main() {
    int r1, c1, r2, c2, r3, c3;

    cin >> r1 >> c1;
    cin >> r2 >> c2;
    cin >> r3 >> c3;

    Matrix A, B, C;
    try {
        A = Matrix(r1, c1);
        B = Matrix(r2, c2);
        C = Matrix(r3, c3);
    } catch (const std::exception& e) {
        cerr << "Error creating matrices: " << e.what() << '\n';
        return 1;
    }   

    A.fillWith(0);
    B.fillWith(0);
    C.fillWith(0);

    try {
        Matrix S = A + B;
        cout << S << '\n'; // เพิ่มบรรทัดว่างตามตัวอย่าง output
    } catch (const std::exception& e) {
        cout << e.what() << '\n';
    }

    try {
        Matrix S = A + C;
        cout << S << '\n';
    } catch (const std::exception& e) {
        cout << e.what() << '\n';
    }

    try {
        Matrix S = B + C;
        cout << S << '\n';
    } catch (const std::exception& e) {
        cout << e.what() << '\n';
    }

    return 0;
}