// ALU.cpp
// COA CO3: Illustrate processor level details about arithmetic operations
// using computer arithmetic algorithms.
// Maps to COA Lab Practical 01 (Design ALU using CPU simulator).
//
// Software model of an ALU: performs ADD/SUB/CMP on register values,
// and sets Zero/Carry/Sign flags, in the style of the 80386 course.

#include <iostream>
using namespace std;

struct Flags { bool zero, carry, sign; };

class ALU {
public:
    Flags flags;

    int add(int a, int b) {
        long result = (long)a + b;
        flags.carry = result > 0xFFFFFFFF;
        int r = (int)result;
        flags.zero = (r == 0);
        flags.sign = (r < 0);
        return r;
    }

    int sub(int a, int b) {
        long result = (long)a - b;
        flags.carry = (a < b);
        int r = (int)result;
        flags.zero = (r == 0);
        flags.sign = (r < 0);
        return r;
    }

    // CMP sets flags but does not return a usable value (like real ALU CMP)
    void cmp(int a, int b) {
        sub(a, b); // internally same as subtraction, flags updated
    }

    void printFlags() {
        cout << "  Flags -> Zero:" << flags.zero << " Carry:" << flags.carry
             << " Sign:" << flags.sign << endl;
    }
};

int main() {
    ALU alu;

    cout << "ALU Demo: wafer defect-count arithmetic\n" << endl;

    int defectCount = 35, threshold = 20;

    cout << "ADD (defectCount + 5): " << alu.add(defectCount, 5) << endl;
    alu.printFlags();

    cout << "\nSUB (defectCount - threshold): " << alu.sub(defectCount, threshold) << endl;
    alu.printFlags();

    cout << "\nCMP (defectCount vs threshold):" << endl;
    alu.cmp(defectCount, threshold);
    alu.printFlags();
    if (!alu.flags.zero && !alu.flags.sign)
        cout << "  Zero=0, Sign=0 => (defectCount - threshold) > 0 => defectCount > threshold => wafer FAILS QC" << endl;
    else if (alu.flags.zero)
        cout << "  Zero=1 => defectCount == threshold => borderline case" << endl;
    else
        cout << "  Sign=1 => defectCount < threshold => wafer PASSES QC" << endl;

    return 0;
}
