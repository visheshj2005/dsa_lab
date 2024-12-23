#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to insert at the front of the doubly linked list
void insertAtFront(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);

    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }

    (*head_ref) = new_node;
}

// Function to insert at the end of the doubly linked list
void insertAtEnd(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

// Function to delete a node in the doubly linked list
void deleteNode(Node** head_ref, Node* del) {
    if (*head_ref == NULL || del == NULL) {
        return;
    }

    if (*head_ref == del) {
        *head_ref = del->next;
    }

    if (del->next != NULL) {
        del->next->prev = del->prev;
    }

    if (del->prev != NULL) {
        del->prev->next = del->next;
    }

    delete del;
}

// Function to display the doubly linked list
void displayList(Node* node) {
    Node* last;
    cout << "Traversal in forward direction: ";
    while (node != NULL) {
        cout << node->data << " ";
        last = node;
        node = node->next;
    }
    cout << endl;

    cout << "Traversal in reverse direction: ";
    while (last != NULL) {
        cout << last->data << " ";
        last = last->prev;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 6);
    insertAtFront(&head, 7);
    insertAtFront(&head, 1);
    insertAtEnd(&head, 4);

    cout << "Created Doubly Linked List: ";
    displayList(head);

    deleteNode(&head, head->next);

    cout << "List after deletion of node at position 2: ";
    displayList(head);

    return 0;
}
