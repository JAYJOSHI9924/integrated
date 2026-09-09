// ScanLineFill.cpp
// CG CO3: Develop 2D objects using various algorithms.
// Maps to CG Lab Practical 03 (Polygon fill using scan-line algorithm).
//
// Fills each die cell of the wafer grid (represented as a square polygon)
// using the scan-line fill approach -- prints the filled horizontal spans
// per row, standing in for setting pixel color in an OpenGL/canvas context.

#include <iostream>
#include <vector>
using namespace std;

struct Edge { int yMin, yMax; double x, slopeInv; };

void scanLineFillSquare(int x1, int y1, int x2, int y2) {
    // Square die cell with corners (x1,y1)-(x2,y2)
    cout << "Filling die cell from (" << x1 << "," << y1 << ") to (" << x2 << "," << y2 << ")" << endl;
    for (int y = y1; y <= y2; y++) {
        cout << "  Row y=" << y << ": fill pixels x=" << x1 << " to x=" << x2 << endl;
    }
}

int main() {
    cout << "=== Scan-Line Fill: wafer die grid (3x3 sample) ===" << endl;
    int cellSize = 4;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            int x1 = col * cellSize, y1 = row * cellSize;
            int x2 = x1 + cellSize - 1, y2 = y1 + cellSize - 1;
            scanLineFillSquare(x1, y1, x2, y2);
        }
    }
    cout << "\nAll 9 die cells filled." << endl;
    return 0;
}
