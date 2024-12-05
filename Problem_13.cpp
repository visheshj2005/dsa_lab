#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
            cout << x << " enqueued to queue\n";
            return;
        }

        rear->next = newNode;
        rear = newNode;
        cout << x << " enqueued to queue\n";
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow\n";
            return 0;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        int data = temp->data;
        delete temp;
        return data;
    }

    int frontElement() {
        if (front == nullptr) {
            cout << "Queue is Empty\n";
            return 0;
        } else {
            return front->data;
        }
    }

    int rearElement() {
        if (rear == nullptr) {
            cout << "Queue is Empty\n";
            return 0;
        } else {
            return rear->data;
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            Node* temp = front;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
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
    q.display();

    return 0;
}
