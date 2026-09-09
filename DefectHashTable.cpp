// DefectHashTable.cpp
// DS CO6 / Prog Lab CO5: Implement/apply the concepts of hashing.
// Maps to Practical 11 (Hashing) of Data Structures Lab.
//
// hash(key) = key mod TABLE_SIZE, collision handling via separate chaining
// (as specified in Practical 11b of the syllabus).

#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 6;

struct DefectNode {
    int defectId;
    string defectName;
    DefectNode* next;
};

class DefectHashTable {
private:
    DefectNode* table[TABLE_SIZE];
    int hashFunction(int key) { return key % TABLE_SIZE; }
public:
    DefectHashTable() { for (int i = 0; i < TABLE_SIZE; i++) table[i] = nullptr; }

    void insert(int id, string name) {
        int idx = hashFunction(id);
        DefectNode* node = new DefectNode{id, name, table[idx]};
        table[idx] = node; // insert at head of chain (collision -> chaining)
        cout << "  Inserted defect ID " << id << " (" << name << ") into bucket " << idx << endl;
    }

    string lookup(int id) {
        int idx = hashFunction(id);
        DefectNode* temp = table[idx];
        while (temp != nullptr) {
            if (temp->defectId == id) return temp->defectName;
            temp = temp->next;
        }
        return "NOT FOUND";
    }

    void printTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "  Bucket " << i << ": ";
            DefectNode* temp = table[i];
            if (!temp) { cout << "(empty)"; }
            while (temp) {
                cout << "[" << temp->defectId << ":" << temp->defectName << "] ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    DefectHashTable dht;

    // Defect type IDs -- note 1 and 7 collide (both hash to bucket 1)
    dht.insert(1, "DONUT");
    dht.insert(2, "SCRATCH");
    dht.insert(3, "RING");
    dht.insert(7, "EDGE_RING"); // collides with id 1 -> demonstrates chaining
    dht.insert(4, "CENTER_CLUSTER");

    cout << "\nHash Table contents:" << endl;
    dht.printTable();

    cout << "\nLookup defect ID 7: " << dht.lookup(7) << endl;
    cout << "Lookup defect ID 99: " << dht.lookup(99) << endl;

    return 0;
}
