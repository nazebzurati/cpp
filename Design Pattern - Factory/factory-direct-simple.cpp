#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

enum class PointType {
    cartesian,
    polar
};

struct Point {
    Point(float a, float b, PointType type = PointType::cartesian) {
        if (type == PointType::cartesian) {
            x = a;
            y = b;
        }
        else {
            x = a * cos(b);
            y = a * sin(b); 
        }
    }
    public:
        float x, y;
};

int main() {
    return 0;
}