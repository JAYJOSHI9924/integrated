// CohenSutherland.cpp
// CG CO5: Implement the suitable clipping algorithms.
// Maps to CG Lab Practical 05 (line clipping using Cohen-Sutherland algorithm).
//
// Clips a line segment against a rectangular "zoom viewport" -- used when
// the user zooms into a defect region so only the region inside the
// viewport is shown.

#include <iostream>
using namespace std;

const int INSIDE = 0, LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
double xmin, ymin, xmax, ymax;

int computeCode(double x, double y) {
    int code = INSIDE;
    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    else if (y > ymax) code |= TOP;
    return code;
}

void cohenSutherlandClip(double x1, double y1, double x2, double y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) { accept = true; break; }
        else if (code1 & code2) break; // trivially reject
        else {
            double x, y;
            int codeOut = code1 ? code1 : code2;
            if (codeOut & TOP) { x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1); y = ymax; }
            else if (codeOut & BOTTOM) { x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1); y = ymin; }
            else if (codeOut & RIGHT) { y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1); x = xmax; }
            else { y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1); x = xmin; }

            if (codeOut == code1) { x1 = x; y1 = y; code1 = computeCode(x1, y1); }
            else { x2 = x; y2 = y; code2 = computeCode(x2, y2); }
        }
    }

    if (accept)
        cout << "  Clipped line: (" << x1 << "," << y1 << ") to (" << x2 << "," << y2 << ")" << endl;
    else
        cout << "  Line lies fully outside the zoom viewport - rejected." << endl;
}

int main() {
    xmin = 10; ymin = 10; xmax = 40; ymax = 40; // zoom viewport (defect region)

    cout << "Zoom viewport: (" << xmin << "," << ymin << ") to (" << xmax << "," << ymax << ")\n" << endl;

    cout << "Clipping line A (0,0) to (50,50) [crosses the viewport]:" << endl;
    cohenSutherlandClip(0, 0, 50, 50);

    cout << "\nClipping line B (60,60) to (80,80) [fully outside]:" << endl;
    cohenSutherlandClip(60, 60, 80, 80);

    return 0;
}
