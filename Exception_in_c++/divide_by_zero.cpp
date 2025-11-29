#include <iostream>
#include <cmath>

using namespace std;

class DivideByZeroException : public exception {
public:
    const char* what() const throw() {
        return "Your input is not valid, you can't divide by zero.";
    }
};

int main() {
    int numerator, denominator, answer;
    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;
    
    try {
        if (denominator == 0) {
            throw DivideByZeroException();
        }
        // your code here
        answer = numerator / denominator;
        cout << answer << endl;
    } catch (const DivideByZeroException& e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
