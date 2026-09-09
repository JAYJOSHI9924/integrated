// Bresenham.cpp
// CG CO1/CO3: OpenGL primitives / Develop 2D objects using algorithms.
// Maps to CG Lab Practical 02 (Bresenham's circle drawing algorithm).
//
// Draws the circular wafer outline using Bresenham's circle algorithm.
// NOTE: This is the algorithmic core (pixel-coordinate generation), tested
// on console. Rendering these points via an OpenGL window requires a
// display/GLUT context, which is not available in this evaluation sandbox
// -- it will be demonstrated on the student's machine (see status notes).

#include <iostream>
using namespace std;

void plotCirclePoints(int xc, int yc, int x, int y, int &count) {
    cout << "  (" << xc+x << "," << yc+y << ") (" << xc-x << "," << yc+y << ") "
         << "(" << xc+x << "," << yc-y << ") (" << xc-x << "," << yc-y << ") "
         << "(" << xc+y << "," << yc+x << ") (" << xc-y << "," << yc+x << ") "
         << "(" << xc+y << "," << yc-x << ") (" << xc-y << "," << yc-x << ")" << endl;
    count += 8;
}

void bresenhamCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    int count = 0;
    plotCirclePoints(xc, yc, x, y, count);
    while (y >= x) {
        x++;
        if (d > 0) { y--; d = d + 4 * (x - y) + 10; }
        else { d = d + 4 * x + 6; }
        plotCirclePoints(xc, yc, x, y, count);
    }
    cout << "\nTotal wafer-boundary pixels plotted: " << count << endl;
}

int main() {
    cout << "Drawing wafer outline (circle) using Bresenham's algorithm." << endl;
    cout << "Center=(50,50), Radius=8\n" << endl;
    bresenhamCircle(50, 50, 8);
    return 0;
}
