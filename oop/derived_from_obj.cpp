#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class AdHocSquare
{
public:
  AdHocSquare(double side){
    this->side = side; 
  }

  void set_side(double side){
    this->side = side; 
  }

  double get_area(){
    return side * side;
  }

    private:
    double side;
};


class LazySquare
{
public:
  LazySquare(double side) {
        this->side = side;
        area = side * side;
        side_changed = false;
    }
    
  void set_side(double side){
    this->side = side;
    side_changed = true;
  }

  double get_area(){
    if(side_changed){
        area = side * side;
        side_changed = false;
    }
    return area;
  }
    private:
    double side;
    double area;
    bool side_changed;
};

int main() {
    AdHocSquare adhoc(4);
    cout << "AdHocSquare area: " << adhoc.get_area() << endl;

    adhoc.set_side(5);
    cout << "AdHocSquare area after change: " << adhoc.get_area() << endl;

    LazySquare lazy(4);
    cout << "LazySquare area: " << lazy.get_area() << endl;

    lazy.set_side(5);
    cout << "LazySquare area after change: " << lazy.get_area() << endl;

    return 0;
}