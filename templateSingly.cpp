#include <iostream>
#include <string>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
void printForward(Node<T>* head);

template <typename T>
void printReverse(Node<T>* head);

template <typename T>
Node<T>* push_back(Node<T>* head, const T& data);

template <typename T>
int countNodes(Node<T>* head);

template <typename T>
void freeList(Node<T>* head);

int main() {
    Node<string>* head = nullptr;
    string input;
    char choice;

    do {
        cout << "Enter a string to add to the list: ";
        getline(cin, input);
        head = push_back(head, input);

        cout << "Do you want to add another node? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    cout << "List in forward order: ";
    printForward(head);

    cout << "List in reverse order: ";
    printReverse(head);
    cout << "nullptr" << endl;

    cout << "Total number of nodes: "
        << countNodes(head) << endl;

    freeList(head);
    return 0;
}

template <typename T>
void printForward(Node<T>* head) {
    Node<T>* current = head;

    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }

    cout << "nullptr" << endl;
}

template <typename T>
void printReverse(Node<T>* head) {
    if (head == nullptr)
        return;

    printReverse(head->next);
    cout << head->data << " -> ";
}

template <typename T>
Node<T>* push_back(Node<T>* head, const T& data) {
    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr)
        return newNode;

    Node<T>* current = head;

    while (current->next != nullptr)
        current = current->next;

    current->next = newNode;
    return head;
}

template <typename T>
int countNodes(Node<T>* head) {
    int count = 0;
    Node<T>* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

template <typename T>
void freeList(Node<T>* head) {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}
