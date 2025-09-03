#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

class Fraction{
public:
  Fraction(int numerator, int denominator);
  string toString();
  double toDouble();
private:
  int numerator;
  int denominator;
};

// implement Fraction methods
Fraction::Fraction(int numerator, int denominator) {
    if(denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    this -> numerator = numerator;
    this -> denominator = denominator;
}

string Fraction::toString(){
    int num = numerator;
    int den = denominator;

    int whole = num / den;
    int remainder = abs(num % den);

    string result;

    if(whole != 0) {
        result = to_string(whole);
        if(remainder != 0) {
            result += " " + to_string(remainder) + "/" + to_string(den);
        }
    } else {
        result = to_string(num) + "/" + to_string(den);
    }

    return result;
}

double Fraction::toDouble(){
    return (double)numerator / denominator;
}

int main(void) {
  
  string input;
    getline(cin, input);

    stringstream ss(input);
    int num, den;
    char slash;
    ss >> num >> slash >> den;

    Fraction fraction(num, den);
  // parse input and get numerator and denominator

	 cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
	return 0;
}