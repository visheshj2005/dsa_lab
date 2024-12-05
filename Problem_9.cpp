#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void insertAtPosition(Node** head_ref, int new_data, int position) {
    Node* new_node = new Node();
    new_node->data = new_data;

    if (position == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    Node* temp = *head_ref;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of bounds" << endl;
        delete new_node;
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    delete temp;
}

void deleteNodeAtPosition(Node** head_ref, int position) {
    if (*head_ref == NULL) return;

    Node* temp = *head_ref;

    if (position == 0) {
        *head_ref = temp->next;
        delete temp;
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return;

    Node* next = temp->next->next;
    delete temp->next;
    temp->next = next;
}

void displayList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    cout << "Linked list after insertion at end: ";
    displayList(head);

    insertAtPosition(&head, 4, 1);
    cout << "Linked list after insertion at position 1: ";
    displayList(head);

    deleteNode(&head, 2);
    cout << "Linked list after deleting 2: ";
    displayList(head);

    deleteNodeAtPosition(&head, 1);
    cout << "Linked list after deleting at position 1: ";
    displayList(head);

    return 0;
}
