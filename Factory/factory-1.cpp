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

// Factory is a method to deal with the problem of creating objects without having to specify the exact
// class of the object that will be created.
// --------------------------------------------------------------------------------------------------------
// For an example in this tutorial, Point class could not have two constructor that have the same 
// argument: Point(float x, float y) for cartesian and Point(float rho, float theta). However, we can use
// one constructor and define it based on its type (in this example, enum class were used). It's just a
// simple if else or switch case would be sufficient to know which operation to be executed.
// --------------------------------------------------------------------------------------------------------
// *compile: g++ -std=c++11 -g Factory/factory-1.cpp -o exec.out