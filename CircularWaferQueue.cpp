// CircularWaferQueue.cpp
// DS CO4 / Prog Lab CO3: Make use of Stack and Queue for scenario based applications.
// Maps to Practical 08 (Circular Queue) of Data Structures Lab.
//
// Simulates multiple uploaded wafers waiting to be processed, FCFS,
// using a circular queue implemented on an array.

#include <iostream>
using namespace std;

const int CAPACITY = 5;

class CircularWaferQueue {
private:
    int wafers[CAPACITY];
    int front, rear, count;
public:
    CircularWaferQueue() { front = 0; rear = -1; count = 0; }

    bool enqueue(int waferId) {
        if (count == CAPACITY) { cout << "  Queue full, cannot upload Wafer #" << waferId << endl; return false; }
        rear = (rear + 1) % CAPACITY;
        wafers[rear] = waferId;
        count++;
        cout << "  Wafer #" << waferId << " added to processing queue." << endl;
        return true;
    }

    bool dequeue() {
        if (count == 0) { cout << "  Queue empty, nothing to process." << endl; return false; }
        cout << "  Processing Wafer #" << wafers[front] << endl;
        front = (front + 1) % CAPACITY;
        count--;
        return true;
    }

    void display() {
        if (count == 0) { cout << "  (queue empty)" << endl; return; }
        int idx = front;
        for (int i = 0; i < count; i++) {
            cout << "  [" << wafers[idx] << "]";
            idx = (idx + 1) % CAPACITY;
        }
        cout << endl;
    }
};

int main() {
    CircularWaferQueue q;

    cout << "Uploading 4 wafers..." << endl;
    q.enqueue(201);
    q.enqueue(202);
    q.enqueue(203);
    q.enqueue(204);

    cout << "\nQueue state: "; q.display();

    cout << "\nProcessing wafers in FCFS order:" << endl;
    q.dequeue();
    q.dequeue();

    cout << "\nQueue state after processing 2: "; q.display();

    return 0;
}
