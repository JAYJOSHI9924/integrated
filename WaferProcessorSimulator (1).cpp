// WaferProcessorSimulator.cpp
// COA CO1/CO4: Explicate 80386 architecture/instruction set;
// Demonstrate control signal generation and instruction execution.
// Maps to COA Lab Practical 02 (Design Control Unit using CPU simulator).
//
// IMPORTANT (honesty note): This is an EDUCATIONAL SOFTWARE SIMULATOR
// modeling register/ALU/control-unit behaviour conceptually. It is NOT a
// real 80386 processor, NOT a cycle-accurate hardware emulator, and does
// NOT execute real x86 machine code / an actual assembler. It reproduces
// the Fetch-Decode-Execute cycle and control signals for a small
// instruction sequence relevant to the wafer QC threshold check.
//
// Program simulated (hand-written pseudo-ALP, see Review 1 report):
//   LOAD R1, DefectCount   ; R1 = 35
//   LOAD R2, Threshold     ; R2 = 20
//   CMP  R1, R2
//   JG   FAIL
//   JMP  PASS
//   FAIL: STORE Result, 1
//   PASS: STORE Result, 0

#include <iostream>
#include <string>
using namespace std;

int main() {
    int R1 = 0, R2 = 0, Result = -1;
    int DefectCount = 35, Threshold = 20;
    int PC = 0;

    string program[7] = {
        "LOAD R1, DefectCount",
        "LOAD R2, Threshold",
        "CMP  R1, R2",
        "JG   FAIL",
        "JMP  PASS",
        "FAIL: STORE Result, 1",
        "PASS: STORE Result, 0"
    };

    cout << "=== Wafer Processor Simulator: Fetch-Decode-Execute Trace ===\n" << endl;

    // Step 1: LOAD R1
    cout << "PC=" << PC << " FETCH: " << program[0] << endl;
    cout << "  DECODE: opcode=LOAD, dest=R1, src=DefectCount" << endl;
    R1 = DefectCount;
    cout << "  EXECUTE: control signal MEM_READ, REG_WRITE(R1) -> R1=" << R1 << endl;
    PC++;

    // Step 2: LOAD R2
    cout << "\nPC=" << PC << " FETCH: " << program[1] << endl;
    cout << "  DECODE: opcode=LOAD, dest=R2, src=Threshold" << endl;
    R2 = Threshold;
    cout << "  EXECUTE: control signal MEM_READ, REG_WRITE(R2) -> R2=" << R2 << endl;
    PC++;

    // Step 3: CMP
    cout << "\nPC=" << PC << " FETCH: " << program[2] << endl;
    cout << "  DECODE: opcode=CMP, R1, R2" << endl;
    int diff = R1 - R2;
    bool signFlag = diff < 0;
    bool zeroFlag = diff == 0;
    cout << "  EXECUTE: control signal ALU_OP=SUB(internal) -> flags: Zero=" << zeroFlag
         << " Sign=" << signFlag << endl;
    PC++;

    // Step 4: JG FAIL (jump if R1 > R2, i.e. diff > 0)
    cout << "\nPC=" << PC << " FETCH: " << program[3] << endl;
    bool jumpTaken = (diff > 0);
    cout << "  DECODE: opcode=JG, target=FAIL" << endl;
    cout << "  EXECUTE: control signal PC_LOAD=" << jumpTaken << endl;

    if (jumpTaken) {
        cout << "\nBranch taken -> PC=5 FETCH: " << program[5] << endl;
        Result = 1;
        cout << "  EXECUTE: control signal MEM_WRITE(Result) -> Result=" << Result << " (DEFECTIVE)" << endl;
    } else {
        cout << "\nBranch not taken -> PC=6 FETCH: " << program[6] << endl;
        Result = 0;
        cout << "  EXECUTE: control signal MEM_WRITE(Result) -> Result=" << Result << " (NORMAL)" << endl;
    }

    cout << "\n=== Final QC Verdict ===" << endl;
    cout << "DefectCount=" << DefectCount << ", Threshold=" << Threshold
         << " -> Result=" << (Result == 1 ? "DEFECTIVE (FAIL)" : "NORMAL (PASS)") << endl;

    return 0;
}
