#include <iostream>
#include <string>

using namespace std;
//add your own exception class here
class AreaException : public exception {
    private:
        string message;
    public:
        AreaException(string msg) : message(msg) {}
        const char* what() const throw() {
        return message.c_str();
    }
};

//add functions code here

float square_area(float a) {
    if ( a <= 0)
        throw AreaException("Your input is not valid. The area can't be negative.");
    return a * a;
}

float rectangle_area(float a, float b) {
    if (a <= 0 || b <= 0)
        throw AreaException("Your input is not valid. The area can't be negative.");
    return a * b;
}


int main(void) {
	float a, b, r;
    cout << "input 1:";
	cin >> a;
    cout << "input 2:";
	cin >> b;
	try
	{
		float rsquare = square_area(a);
		float rrectangle = rectangle_area(a,b);
		cout << rsquare << endl << rrectangle << endl;
	} catch (AreaException& e) {
        cout << e.what() << endl;
    }
	//add a suitable catch block here
	return 0;
}