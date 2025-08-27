#include <iostream>
#include <string>

using namespace std;

class Square
{
  private:
    double side;
    double area;

    public:
    // Constructor
    Square(double side) {
        set_side(side); // use the setter for consistency
    }

    // Setter (updates both side and area, ignores negatives)
    void set_side(double s) {
        if (s >= 0) {
            side = s;
            area = s * s;
        } // if s < 0, ignore
    }

    // Getter (optional, but good practice)
    double get_side() {
        return side;
    }

    double get_area() {
        return area;
    }

    // Print method
    void print() {
        cout << "Square: side=" << side << " area=" << area << endl;
    }
};


int main() {
    Square s(4);

    s.print();        

    s.set_side(2.0);  
    s.print();

    s.set_side(-33.0); 
    s.print();

    return 0;
}