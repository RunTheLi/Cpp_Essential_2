#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

class Point2D{
public:
  Point2D(double x, double y);
  string toString();
  double toDouble();
  // ...
  double distanceTo(Point2D that);
private:
  double x;
  double y;
};

// implement Point2D methods
Point2D::Point2D(double x, double y){
    this-> x = x;
    this-> y = y;
}

string Point2D::toString(){
    stringstream ss;
    ss << "(" << x << ", " << y << ")";
    return ss.str();
}

double Point2D::toDouble(){
    return sqrt(x * x + y * y);
}

double Point2D::distanceTo(Point2D that) {
    double dx = this -> x - that.x;
    double dy = this -> y - that.y;
    return sqrt(dx * dx + dy * dy);
}

int main () {

    double x1, y1, x2, y2;

    // Read two points
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    Point2D p1(x1, y1);
    Point2D p2(x2, y2);

    // Output the distance
    cout << p1.distanceTo(p2) << endl;
    
    return 0;
}