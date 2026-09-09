
#include <iostream>
using namespace std;

const int N = 6; // sample wafer grid size (NxN dies)

void printWafer(int wafer[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << wafer[i][j] << " ";
        cout << endl;
    }
}

double computeDefectDensity(int wafer[N][N]) {
    int totalDies = N * N;
    int defectiveDies = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (wafer[i][j] == 1) defectiveDies++;
    return (double)defectiveDies / totalDies * 100.0;
}

int countDefectiveDies(int wafer[N][N]) {
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (wafer[i][j] == 1) count++;
    return count;
}

int main() {
    // Sample wafer map (simulated ring-shaped defect cluster, like a DONUT pattern)
    int wafer[N][N] = {
        {0,0,1,1,0,0},
        {0,1,0,0,1,0},
        {1,0,0,0,0,1},
        {1,0,0,0,0,1},
        {0,1,0,0,1,0},
        {0,0,1,1,0,0}
    };

    cout << "=== Wafer Map (0=Good, 1=Defective) ===" << endl;
    printWafer(wafer);

    int defectCount = countDefectiveDies(wafer);
    double density = computeDefectDensity(wafer);

    cout << "\nTotal Dies: " << N * N << endl;
    cout << "Defective Dies: " << defectCount << endl;
    cout << "Defect Density: " << density << " %" << endl;

    return 0;
}
