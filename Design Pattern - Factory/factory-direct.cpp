#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

enum class PointType {
    cartesian,
    polar
};

struct Point {

    // friend class PointFactory; // violates Open-Close Principle: Point struct will have factory automatically even though it isn't needed

    public:
        float x, y;
        Point(float a, float b): x(a), y(b) {};
        friend ostream &operator <<(ostream &os, const Point &point) {
            os << "x: " << point.x << " y: " << point.y;
            return os;
        }
};

struct PointFactory {

    static Point NewCartesian(float x, float y) {
        return { x, y };
    }
    static Point NewPolar(float r, float theta) {
        return { r*cos(theta), r*sin(theta) } ;
    }
};

int main() {

    Point p1 = PointFactory::NewPolar(5, M_PI_4);
    cout << p1 << endl;
    
    Point p2 {3, 3};
    cout << p2 << endl;

    return 0;
}