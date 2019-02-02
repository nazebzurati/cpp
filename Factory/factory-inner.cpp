#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

enum class PointType {
    cartesian,
    polar
};

struct Point {

    public:
        float x, y;
        Point(float a, float b): x(a), y(b) {};
        friend ostream &operator <<(ostream &os, const Point &point) {
            os << "x: " << point.x << " y: " << point.y;
            return os;
        }

    private:
        class PointFactory {
            public:
                static Point NewCartesian(float x, float y) {
                    return { x, y };
                }
                static Point NewPolar(float r, float theta) {
                    return { r*cos(theta), r*sin(theta) } ;
                }
        };

    public:
        static PointFactory Factory;
};

int main() {

    Point p1 = Point::Factory.NewPolar(5, M_PI_4);
    cout << p1 << endl;

    return 0;
}

// Factory is a method to deal with the problem of creating objects without having to specify the exact
// class of the object that will be created.
// --------------------------------------------------------------------------------------------------------
// *compile: g++ -std=c++11 -g Factory/factory-inner.cpp -o exec.out