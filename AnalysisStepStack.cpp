// AnalysisStepStack.cpp
// DS CO4 / Prog Lab CO3: Make use of Stack and Queue for scenario based applications.
// Related concept from Practical 06 (Stack) of Data Structures Lab.
//
// Tracks the sequence of analysis steps applied to a wafer image
// (Raw -> Preprocessed -> Thresholded -> Classified -> Heatmapped)
// so the UI can "undo" back to a previous view. Stack is appropriate
// because undo is inherently Last-In-First-Out.

#include <iostream>
#include <string>
using namespace std;

const int MAX_STEPS = 10;

class AnalysisStepStack {
private:
    string steps[MAX_STEPS];
    int top;
public:
    AnalysisStepStack() { top = -1; }

    void push(string step) {
        if (top == MAX_STEPS - 1) { cout << "  Stack full, cannot push " << step << endl; return; }
        steps[++top] = step;
        cout << "  Applied step: " << step << endl;
    }

    void undo() {
        if (top == -1) { cout << "  Nothing to undo." << endl; return; }
        cout << "  Undoing step: " << steps[top] << endl;
        top--;
    }

    string currentView() {
        if (top == -1) return "RAW (no steps applied)";
        return steps[top];
    }
};

int main() {
    AnalysisStepStack stack;

    stack.push("Preprocessed");
    stack.push("Thresholded");
    stack.push("Classified");
    stack.push("Heatmapped");

    cout << "\nCurrent view: " << stack.currentView() << endl;

    cout << "\nUser clicks Undo twice:" << endl;
    stack.undo();
    stack.undo();

    cout << "\nCurrent view after undo: " << stack.currentView() << endl;

    return 0;
}
