// WaferSearchSort.cpp
// DS CO5 / Prog Lab CO4: Apply appropriate searching and sorting algorithm.
// Maps to Practical 10 (Searching and Sorting) of Data Structures Lab.
//
// Sorts inspection records by severity score (Quick Sort) and
// performs binary search on a sorted defect-ID array.

#include <iostream>
using namespace std;

struct InspectionRecord {
    int waferId;
    int severity; // 0-100, higher = more severe
};

// ---- Quick Sort on severity (descending) ----
void swapRecords(InspectionRecord &a, InspectionRecord &b) {
    InspectionRecord temp = a; a = b; b = temp;
}

int partition(InspectionRecord arr[], int low, int high) {
    int pivot = arr[high].severity;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].severity > pivot) { // descending order
            i++;
            swapRecords(arr[i], arr[j]);
        }
    }
    swapRecords(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(InspectionRecord arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---- Binary Search on sorted defect-ID array ----
int binarySearch(int arr[], int size, int key) {
    int lo = 0, hi = size - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main() {
    InspectionRecord records[5] = {
        {301, 40}, {302, 90}, {303, 15}, {304, 70}, {305, 55}
    };

    cout << "Before sorting (by wafer ID order):" << endl;
    for (auto &r : records) cout << "  Wafer #" << r.waferId << " severity=" << r.severity << endl;

    quickSort(records, 0, 4);

    cout << "\nAfter Quick Sort (by severity, descending):" << endl;
    for (auto &r : records) cout << "  Wafer #" << r.waferId << " severity=" << r.severity << endl;

    int defectIds[6] = {1, 2, 3, 4, 5, 6}; // sorted defect-type IDs
    int key = 4;
    int idx = binarySearch(defectIds, 6, key);

    cout << "\nBinary search for defect ID " << key << ": ";
    if (idx != -1) cout << "found at index " << idx << endl;
    else cout << "not found" << endl;

    return 0;
}
