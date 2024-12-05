#include <iostream>
using namespace std;

#define MAX 1000

class Queue {
    int front, rear, size;
    int arr[MAX];
public:
    Queue() {
        front = size = 0;
        rear = MAX - 1;
    }

    bool enqueue(int x) {
        if (size >= MAX) {
            cout << "Queue Overflow\n";
            return false;
        } else {
            rear = (rear + 1) % MAX;
            arr[rear] = x;
            size++;
            cout << x << " enqueued to queue\n";
            return true;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return 0;
        } else {
            int item = arr[front];
            front = (front + 1) % MAX;
            size--;
            return item;
        }
    }

    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return 0;
        } else {
            return arr[front];
        }
    }

    int rearElement() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return 0;
        } else {
            return arr[rear];
        }
    }

    bool isEmpty() {
        return (size == 0);
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.dequeue() << " dequeued from queue\n";
    cout << "Front element is " << q.frontElement() << endl;
    cout << "Rear element is " << q.rearElement() << endl;
    cout << "Queue is empty: " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
