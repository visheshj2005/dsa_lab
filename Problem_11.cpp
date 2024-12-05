#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}

    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << x << " pushed into stack\n";
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return 0;
        } else {
            Node* temp = top;
            top = top->next;
            int popped = temp->data;
            delete temp;
            return popped;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return 0;
        } else {
            return top->data;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
        } else {
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " popped from stack\n";
    cout << "Top element is " << s.peek() << endl;
    cout << "Stack is empty: " << (s.isEmpty() ? "Yes" : "No") << endl;
    s.display();

    return 0;
}
