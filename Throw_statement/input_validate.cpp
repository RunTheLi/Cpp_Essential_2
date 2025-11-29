#include <iostream>

using namespace std;
const int DivideByZero = 111;

using namespace std;
float internaldiv(float arg1, float arg2)
{
	if (0==arg2)	
		throw DivideByZero;
	return arg1 / arg2;
}

bool div(float &res, float arg1, float arg2) {
	if(arg2 == 0.0)
		return false;
	res = internaldiv(arg1, arg2);
	return true;
}

int main(void) {
	float r, a, b;
    int c;
    cout << "arg1:";
	while(cin >> a) {
        cout << "arg2:";
		cin >> b;
		if(div(r,a,b))
			cout << r << endl;
		else
			cout << "Are you kidding me?" << endl;

        try {
            if (b == 0) {
                throw runtime_error("Your input is not valid, you can't divide by zero.");
            }

        }
            catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
            
	}
	return 0;
}