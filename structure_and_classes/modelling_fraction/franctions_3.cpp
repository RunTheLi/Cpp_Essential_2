#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Fraction{
public:
  Fraction(int numerator, int denominator);
  string toString();
  double toDouble();
  // ...
  bool isGreaterThan(Fraction that);
  bool isLessThan(Fraction that);
  bool isEqual(Fraction that);
private:
  int numerator;
  int denominator;
  void reduce();
  int gcd(int a, int b);
};

// implement Fraction comparison methods

Fraction::Fraction(int numerator, int denominator) {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    this->numerator = numerator;
    this->denominator = denominator;
    reduce();
}

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

bool Fraction::isGreaterThan(Fraction that){
    return (this->numerator * that.denominator) > (that.numerator * this->denominator);
}

bool Fraction::isLessThan(Fraction that){
    return (this->numerator * that.denominator) < (that.numerator * this->denominator);
}

bool Fraction::isEqual(Fraction that){
    return (this->numerator * that.denominator) == (that.numerator * this->denominator);
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

    if (f1.isEqual(f2)) {
        cout << f1.toString() << " = " << f2.toString() << endl;
    } else if (f1.isGreaterThan(f2)) {
        cout << f1.toString() << " > " << f2.toString() << endl;
    } else {
        cout << f1.toString() << " < " << f2.toString() << endl;
    }

    return 0;
}