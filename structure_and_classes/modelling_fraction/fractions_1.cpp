#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

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

Fraction::Fraction(int numerator, int denominator) {
  if(denominator < 0){
    numerator -= numerator;
    denominator -= denominator;
  }

  this -> numerator = numerator;
  this -> denominator = denominator;
}

string Fraction::toString(){
  int num = numerator;
  int den = denominator;

  int whole = num/denominator;
  int remainder = abs(num % den);

  string result;
  if (whole != 0) {
    result = to_string(whole);
    if (remainder != 0) {
      result += " " + to_string(remainder) + "/" + to_string(den);
    }
  } else {
        // just a fraction
        result = to_string(num) + "/" + to_string(den);
    }
    return result;
}

double Fraction::toDouble(){
  return (double)numerator/denominator;
}
// implement Fraction methods

int main(void) {
    string input;
    getline(cin, input);

    stringstream ss(input);
    int num, den;
    char slash;
    ss >> num >> slash >> den;

    Fraction fraction(num, den);

    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;

    return 0;
}