// Transformations.cpp
// CG CO2: Solve real time problems using geometric transformations.
// Maps to CG Lab Practical 04 (transformation matrices, rotate about a point).
//
// Applies translation, scaling and rotation to wafer view coordinates
// (pan / zoom / rotate operations on the wafer visualization).

#include <iostream>
#include <cmath>
using namespace std;

struct Point { double x, y; };

Point translate(Point p, double dx, double dy) {
    return { p.x + dx, p.y + dy };
}

Point scale(Point p, double sx, double sy) {
    return { p.x * sx, p.y * sy };
}

Point rotate(Point p, double angleDeg) {
    double rad = angleDeg * M_PI / 180.0;
    return { p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad) };
}

void printPoint(string label, Point p) {
    cout << "  " << label << ": (" << p.x << ", " << p.y << ")" << endl;
}

int main() {
    Point waferCenter = {50, 50}; // wafer view center on screen

    cout << "Original wafer center position:" << endl;
    printPoint("original", waferCenter);

    Point panned = translate(waferCenter, 20, -10);
    cout << "\nAfter pan (dx=20, dy=-10):" << endl;
    printPoint("panned", panned);

    Point zoomed = scale(waferCenter, 1.5, 1.5);
    cout << "\nAfter zoom (scale=1.5x):" << endl;
    printPoint("zoomed", zoomed);

    Point rotated = rotate(waferCenter, 45);
    cout << "\nAfter rotate (45 degrees about origin):" << endl;
    printPoint("rotated", rotated);

    return 0;
}
