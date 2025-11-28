#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MatrixSizeMismatch : public runtime_error {
    public:
        MatrixSizeMismatch(const string& msg) : runtime_error(msg) {}
};
    
class MatrixMultiplyMismatch : public runtime_error {
    public:
        MatrixMultiplyMismatch(const string& msg) : runtime_error(msg) {}
};

class IndexOutOfRange : public runtime_error {
    public:
        IndexOutOfRange(const string& msg) : runtime_error(msg) {}
};

class Matrix {
    private:
        int rows;
        int cols;
        vector<vector<int>> data;

        void checkIndices(int r, int c) const;
        void ensureSameSize(const Matrix& other) const;
        void ensureMultiplicable(const Matrix& other) const;
    public:
        Matrix() {
            rows = 0;
            cols = 0;
            data = {};
        }

        Matrix(int r, int c) {
            rows = r;
            cols = c;
            data = vector<vector<int>>(rows, vector<int>(cols, 0));
        }

        Matrix(int r, int c, int fillValue) {
            rows = r;
            cols = c;
            data = vector<vector<int>>(rows, vector<int>(cols, fillValue));
        }

        int& at(int r, int c);
        int at(int r, int c) const;

        Matrix addScalar(int value) const;
        Matrix addMatrix(const Matrix& other) const;
        Matrix subtractScalar(int value) const;
        Matrix subtractMatrix(const Matrix& other) const;
        Matrix multiplyScalar(int value) const;
        Matrix multiplyMatrix(const Matrix& other) const;

        Matrix operator+(const Matrix& other) const; // matrix + matrix
        Matrix operator+(int scalar) const; // matrix + scalar
        friend Matrix operator+(int scalar, const Matrix& m); // scalar + matrix
        Matrix operator-(const Matrix& other) const;
        Matrix operator-(int scalar) const;
        friend Matrix operator-(int scalar, const Matrix& m); // (ถ้าต้องการ)
        Matrix operator*(const Matrix& other) const; // matrix * matrix
        Matrix operator*(int scalar) const;
        friend Matrix operator*(int scalar, const Matrix& m);

        Matrix& operator+=(const Matrix& other);
        Matrix& operator+=(int scalar);
        Matrix& operator-=(const Matrix& other);
        Matrix& operator-=(int scalar);
        Matrix& operator*=(int scalar);

        friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
};

void Matrix::checkIndices(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols) {
        throw IndexOutOfRange("Index out of range");
    }
}

int& Matrix::at(int r, int c){
    checkIndices(r, c);
    return data[r][c];
}

int Matrix::at(int r, int c) const {
    checkIndices(r, c);
    return data[r][c];
}

void Matrix::ensureSameSize(const Matrix& other) const {
    if( rows != other.rows || cols != other.cols) {
        throw MatrixSizeMismatch("Matrix sizes do not match");
    }
}

void Matrix::ensureMultiplicable(const Matrix& other) const {
    if (cols != other.rows) {
        throw MatrixMultiplyMismatch("Matrix dimensions incompatible for multiplication");
    }
}

Matrix Matrix::addScalar(int value) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] + value;
    return result;
}

Matrix Matrix::subtractScalar(int value) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] - value;
    return result;
}

Matrix Matrix::multiplyScalar(int value) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] * value;
    return result;
}

Matrix Matrix::addMatrix(const Matrix& other) const {
    ensureSameSize(other);
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

Matrix Matrix::subtractMatrix(const Matrix& other) const {
    ensureSameSize(other);
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] - other.data[i][j];
    return result;
}

Matrix Matrix::multiplyMatrix(const Matrix& other) const { 
    ensureMultiplicable(other);
    Matrix result(rows, other.cols, 0);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < other.cols; ++j)
            for (int k = 0; k < cols; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
}

ostream& operator<<(ostream& os, const Matrix& m) {
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j)
            os << m.data[i][j] << " ";
        os << "\n";
    }
    return os;
}

Matrix Matrix::operator+(const Matrix& other) const {
    return addMatrix(other);
}

Matrix Matrix::operator+(int scalar) const {
    return addScalar(scalar);
}

Matrix operator+(int scalar, const Matrix& m) {
    return m.addScalar(scalar);
}

Matrix Matrix::operator-(const Matrix& other) const {
    return subtractMatrix(other);
}

Matrix Matrix::operator-(int scalar) const {
    return subtractScalar(scalar);
}

Matrix operator-(int scalar, const Matrix& m){
    return m.subtractScalar(scalar);
}

Matrix Matrix::operator*(const Matrix& other) const{
    return multiplyMatrix(other);
}

Matrix Matrix::operator*(int scalar) const{
    return multiplyScalar(scalar);
}

Matrix operator*(int scalar, const Matrix& m){
    return m.multiplyScalar(scalar);
}

//operator+= 
Matrix& Matrix::operator+=(const Matrix& other) {
    *this = addMatrix(other);
    return *this;
}

Matrix& Matrix::operator+=(int scalar) {
    *this = addScalar(scalar);
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    *this = subtractMatrix(other);
    return *this;
}

Matrix& Matrix::operator-=(int scalar) {
    *this = subtractScalar(scalar);
    return *this;
}

Matrix& Matrix::operator*=(int scalar) {
    *this = multiplyScalar(scalar);
    return *this;
}

int main () {
    try{
        string op;
        cout << "Enter the operation you want to perform (add, subtract, multiply): ";
        cin >> op;

        int rowsA, colsA;

        cout << "Enter the number of rows for Matrix A: ";
        cin >> rowsA;
        cout << "Enter the number of columns for Matrix A: ";
        cin >> colsA;

        Matrix A(rowsA, colsA);
        cout << "Enter the values for Matrix A:\n";
        for(int i = 0; i < rowsA; i++) { 
            for (int j = 0; j < colsA; j++){
                int val;
                cout << "Enter value at position [" << i << "][" << j << "]:";
                cin >> val;
                A.at(i, j) = val;

            }
        }

    int rowsB, colsB;
        cout << "Enter the number of rows for Matrix B: ";
        cin >> rowsB;
        cout << "Enter the number of columns for Matrix B: ";
        cin >> colsB;

        Matrix B(rowsB, colsB);
        cout << "Enter the values for Matrix B:\n";
        for (int i = 0; i < rowsB; i++) {
            for (int j = 0; j < colsB; j++) {
                int val;
                cout << "Enter value at position [" << i << "][" << j << "]: ";
                cin >> val;
                B.at(i, j) = val;
            }
        }

        // === PRINT MATRICES ===
        cout << "\nMatrix A:\n" << A << "\n";
        cout << "Matrix B:\n" << B << "\n";

        // === PERFORM OPERATION ===
        Matrix result;
        if (op == "add") {
            result = A + B;
        } else if (op == "subtract") {
            result = A - B;
        } else if (op == "multiply") {
            result = A * B;
        } else {
            cout << "Invalid operation.\n";
            return 0;
        }

        // === PRINT RESULT ===
        cout << "Result:\n" << result << endl;
    }
    catch (const MatrixSizeMismatch& e) {
        cout << "Exception: Matrix sizes do not match for addition" << endl;
    }
    catch (const MatrixMultiplyMismatch& e) {
        cout << "Exception: Matrix dimensions do not match for multiplication" << endl;
    }
    catch (const IndexOutOfRange& e) {
        cout << "Exception: Index out of range" << endl;
    }
    catch (...) {
        cout << "Unknown error occurred.\n";
    }

    return 0;
}
