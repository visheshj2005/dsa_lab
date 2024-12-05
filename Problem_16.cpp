#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
};

// Function to create a new node
Node* createNode(int coeff, int pow) {
    Node* newNode = new Node();
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = nullptr;
    return newNode;
}

// Function to add a new node to the end of the linked list
void addNode(Node** poly, int coeff, int pow) {
    Node* newNode = createNode(coeff, pow);
    if (*poly == nullptr) {
        *poly = newNode;
    } else {
        Node* temp = *poly;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the polynomial
void displayPoly(Node* poly) {
    while (poly != nullptr) {
        cout << poly->coeff << "x^" << poly->pow;
        poly = poly->next;
        if (poly != nullptr)
            cout << " + ";
    }
    cout << endl;
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;

    while (poly1 != nullptr && poly2 != nullptr) {
        if (poly1->pow > poly2->pow) {
            addNode(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            addNode(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            addNode(&result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != nullptr) {
        addNode(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    while (poly2 != nullptr) {
        addNode(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;

    // Creating first polynomial: 3x^5 + 4x^2 + 2x^1
    addNode(&poly1, 3, 5);
    addNode(&poly1, 4, 2);
    addNode(&poly1, 2, 1);

    // Creating second polynomial: 5x^4 + 2x^2 + 1x^0
    addNode(&poly2, 5, 4);
    addNode(&poly2, 2, 2);
    addNode(&poly2, 1, 0);

    cout << "First Polynomial: ";
    displayPoly(poly1);

    cout << "Second Polynomial: ";
    displayPoly(poly2);

    Node* sum = addPolynomials(poly1, poly2);
    cout << "Sum of Polynomials: ";
    displayPoly(sum);

    return 0;
}
