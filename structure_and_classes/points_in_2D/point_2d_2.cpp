#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

class Point2D{
public:
  Point2D(double x, double y);
  string toString();
  double getX();
  double getY();
  double distanceTo(Point2D that);
  // ...
private:
  double x;
  double y;
};

class Line2D{
public:
  Line2D(double slope, double y_intercept);
  Line2D(Point2D pointA, Point2D pointB);
  string toString();
  
  // ...
private:
  double slope;
  double y_intercept;
};

// implement Point2D and Line2D methods
Point2D::Point2D(double x, double y) {
    this -> x = x;
    this -> y = y;
}

string Point2D::toString(){
    stringstream ss;
    ss << "(" << x << ", " << y << ")";
    return ss.str();
}

double Point2D::getX() { return x; }
double Point2D::getY() { return y; }

double Point2D::distanceTo(Point2D that) {
    double dx = x - that.getX();
    double dy = y - that.getY();
    return sqrt(dx * dx + dy * dy);
}

Line2D::Line2D(double slope, double y_intercept){
    this -> slope = slope;
    this -> y_intercept = y_intercept;
}

Line2D::Line2D(Point2D pointA, Point2D pointB){
    if(pointA.getX() == pointB.getY()){
        slope = INFINITY;
        y_intercept = NAN;
    } else {
        slope = (pointB.getY() - pointA.getY()) / (pointB.getX() - pointA.getX());
        y_intercept = pointA.getY() - slope * pointA.getX();
    }
}

string Line2D::toString(){
    if ( slope == INFINITY ) {
        return "x = constant (vertical line)";
    }
    stringstream ss;
    ss << "y = " << slope << "x + " << y_intercept;
    return ss.str();
}

int main () {

    double x1, y1, x2, y2;

    // Read two points
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    Point2D p1(x1, y1);
    Point2D p2(x2, y2);

    // Output the distance
    double distance = p1.distanceTo(p2);

    cout << distance << endl;
    
    return 0;
}