
#include <iostream>
#include <string>
using namespace std;

struct InspectionRecord {
    int waferId;
    string result;      // "NORMAL" or "DEFECTIVE"
    string defectType;  // e.g. "DONUT", "NONE"
    InspectionRecord* next;
};

class InspectionHistory {
private:
    InspectionRecord* head;
public:
    InspectionHistory() { head = nullptr; }

    void insert(int id, string result, string defectType) {
        InspectionRecord* node = new InspectionRecord{id, result, defectType, nullptr};
        if (head == nullptr) { head = node; return; }
        InspectionRecord* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = node;
    }

    bool deleteById(int id) {
        InspectionRecord *temp = head, *prev = nullptr;
        while (temp != nullptr && temp->waferId != id) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) return false; // not found
        if (prev == nullptr) head = temp->next;
        else prev->next = temp->next;
        delete temp;
        return true;
    }

    InspectionRecord* search(int id) {
        InspectionRecord* temp = head;
        while (temp != nullptr) {
            if (temp->waferId == id) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void traverse() {
        InspectionRecord* temp = head;
        if (temp == nullptr) { cout << "  (history empty)" << endl; return; }
        while (temp != nullptr) {
            cout << "  Wafer #" << temp->waferId << " -> " << temp->result
                 << " (" << temp->defectType << ")" << endl;
            temp = temp->next;
        }
    }
};

int main() {
    InspectionHistory history;

    cout << "Inserting inspection records..." << endl;
    history.insert(101, "NORMAL", "NONE");
    history.insert(102, "DEFECTIVE", "DONUT");
    history.insert(103, "DEFECTIVE", "SCRATCH");

    cout << "\nCurrent history:" << endl;
    history.traverse();

    cout << "\nSearching for Wafer #102..." << endl;
    InspectionRecord* found = history.search(102);
    if (found) cout << "  Found: " << found->result << ", " << found->defectType << endl;
    else cout << "  Not found." << endl;

    cout << "\nDeleting Wafer #101..." << endl;
    history.deleteById(101);

    cout << "\nHistory after deletion:" << endl;
    history.traverse();

    return 0;
}
