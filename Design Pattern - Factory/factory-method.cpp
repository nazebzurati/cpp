#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

enum class PointType {
    cartesian,
    polar
};

struct Point {
    Point(float a, float b): x(a), y(b) {};

    public:
        float x, y;
        static Point NewCartesian(float x, float y) {
            return { x, y };
        }
        static Point NewPolar(float r, float theta) {
            return { r*cos(theta), r*sin(theta) } ;
        }
        friend ostream &operator <<(ostream &os, const Point &point) {
            os << "x: " << point.x << " y: " << point.y;
            return os;
        }
};

int main() {

    Point p = Point::NewPolar(5, M_PI_4);
    cout << p << endl;

    return 0;
}