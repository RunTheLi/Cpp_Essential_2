#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class BoundedValue {
private:
    int value;
    int minValue;
    int maxValue;

public:
    BoundedValue(int val, int minVal, int maxVal) {
        if (val < minVal || val > maxVal)
            throw invalid_argument("Initial value out of bounds");
        value = val;
        minValue = minVal;
        maxValue = maxVal;
    }

    void add(int x) {
        if (value + x > maxValue)
            throw runtime_error("Value could exceed limit.");
        value += x;
    }

    void subtract(int x) {
        if (value - x < minValue)
            throw runtime_error("Value could exceed limit.");
        value -= x;
    }

    int getValue() const {
         return value; 
    }
};

int main() {
    int val1, min1, max1;
    cin >> val1 >> min1 >> max1;
    int val2, min2, max2;
    cin >> val2 >> min2 >> max2;

    try {
        BoundedValue obj1(val1, min1, max1);
        BoundedValue obj2(val2, min2, max2);

        try {
             obj1.add(15); 
            } catch (const exception& e) {
                cout << e.what() << '\n'; }

        try {
             obj1.add(15); 
            } catch (const exception& e) {
                cout << e.what() << '\n'; }

        try {
             obj2.add(15); 
            } catch (const exception& e) {
                cout << e.what() << '\n'; }
            
        cout << obj1.getValue() << '\n';
        cout << obj2.getValue() << '\n';

    } catch (const exception& e) {
        cerr << "Error creating objects: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
