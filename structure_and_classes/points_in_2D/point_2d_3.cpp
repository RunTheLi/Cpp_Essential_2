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
  bool contains(Point2D point);
  // ...
private:
  double slope;
  double y_intercept;
  double x_const;
  bool vertical;
};

// implement Point2D and Line2D methods
string Point2D::toString(){
    stringstream ss;
    ss << "(" << x << ", " << y << ")";
    return ss.str();
}

double Point2D::getX(){ return x; };
double Point2D::getY(){ return y; };

Point2D::Point2D(double x, double y){
    this -> x = x;
    this -> y = y;
}

double Point2D::distanceTo(Point2D that){
    double dx = x - that.getX();
    double dy = y - that.getY();
    return sqrt(dx * dx + dy * dy);
}

Line2D::Line2D(double slope, double y_intercept){
    this -> slope = slope;
    this -> y_intercept = y_intercept;
}

Line2D::Line2D(Point2D pointA, Point2D pointB){
    if(pointA.getX() == pointB.getY()) {
        slope = INFINITY;
        y_intercept = NAN;
    } else { //m=y2-y1/x2-x1 if not veertical line
        slope = (pointB.getY() - pointA.getY()) / (pointB.getX() - pointA.getX());
        // b=y1​−m⋅x1​ for y intercept
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

bool Line2D::contains(Point2D point){
    double epsilon = 1e-6;
    if (vertical) {
        return fabs(point.getX() - x_const) < epsilon;
    } // y=m*x+b for non-vertical line
    double expectedY = slope * point.getX() + y_intercept;
    return fabs(point.getY() - expectedY) < epsilon;
}

int main() {
    double x1, y1, x2, y2, x3, y3;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    Point2D p1(x1, y1);
    Point2D p2(x2, y2);
    Point2D p3(x3, y3);

    Line2D line(p1, p2);

    if (line.contains(p3)) {
        cout << "collinear" << endl;
    } else {
        cout << "not collinear" << endl;
    }

    return 0;
}