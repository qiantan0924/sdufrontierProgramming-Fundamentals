#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    Point(double x = 0., double y = 0.0) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

private:
    double x;
    double y;
};

class Circle : public Point {
public:
    Circle(double r, double x = 0., double y = 0.) : Point(x, y), r(r) {}

    double getR() const { return r; }

    double area() const {
        return M_PI * r * r;
    }

    double cfer() const {
        return 2 * M_PI * r;
    }

private:
    double r;
};

class Cylinder : public Circle {
public:
    Cylinder(double h, double r, double x = 0., double y = 0.) : Circle(r, x, y), h(h) {}

    double geth() const { return h; }

    double v() const {
        return area() * h;
    }

private:
    double h;
};

int main() {
    Circle circle(3.0, 1.0, 2.0);
    cout << "Circle s: " << circle.area() << endl;
    cout << "Circle Circumference: " << circle.cfer() << endl;

    Cylinder cylinder(4.0, 3.0, 1.0, 2.0);
    cout << "Cylinder V: " << cylinder.v() << endl;

    return 0;
}
