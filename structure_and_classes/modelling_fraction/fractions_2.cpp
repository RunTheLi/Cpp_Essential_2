#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();

    Fraction plus(Fraction that);
    Fraction minus(Fraction that);
    Fraction times(Fraction that);
    Fraction by(Fraction that);

private:
    int numerator;
    int denominator;
    void reduce();
    int gcd(int a, int b);
};

// Constructor
Fraction::Fraction(int numerator, int denominator) {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    this->numerator = numerator;
    this->denominator = denominator;
    reduce();
}

// Euclidean algorithm
//Greatest Common Divisor
//12/18 → divide top and bottom by gcd(12,18)=6 → 2/3
int Fraction::gcd(int a, int b) {
    if (b == 0) return abs(a);
    return gcd(b, a % b);
}

// Reduce to lowest terms
void Fraction::reduce() {
    int g = gcd(numerator, denominator);
    if (g != 0) {
        numerator /= g;
        denominator /= g;
    }
}

// String representation
string Fraction::toString() {
    int whole = numerator / denominator;
    int remainder = abs(numerator % denominator);

    if (remainder == 0) {
        return to_string(whole); // pure integer
    }

    if (whole != 0) {
        return to_string(whole) + " " + to_string(remainder) + "/" + to_string(denominator);
    }

    return to_string(numerator) + "/" + to_string(denominator);
}

// Decimal representation
double Fraction::toDouble() {
    return (double)numerator / denominator;
}

// Arithmetic
Fraction Fraction::plus(Fraction that) {
    int num = this->numerator * that.denominator + that.numerator * this->denominator;
    int den = this->denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::minus(Fraction that) {
    int num = this->numerator * that.denominator - that.numerator * this->denominator;
    int den = this->denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::times(Fraction that) {
    int num = this->numerator * that.numerator;
    int den = this->denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::by(Fraction that) {
    int num = this->numerator * that.denominator;
    int den = this->denominator * that.numerator;
    return Fraction(num, den);
}

int main() {
    string input1, input2;
    getline(cin, input1);
    getline(cin, input2);

    stringstream ss1(input1), ss2(input2);
    int n1, d1, n2, d2;
    char slash;

    ss1 >> n1 >> slash >> d1;
    ss2 >> n2 >> slash >> d2;

    Fraction f1(n1, d1), f2(n2, d2);

    cout << f1.toString() << " + " << f2.toString() << " = " << f1.plus(f2).toString() << endl;
    cout << f1.toString() << " - " << f2.toString() << " = " << f1.minus(f2).toString() << endl;
    cout << f1.toString() << " * " << f2.toString() << " = " << f1.times(f2).toString() << endl;
    cout << f1.toString() << " / " << f2.toString() << " = " << f1.by(f2).toString() << endl;

    return 0;
}
