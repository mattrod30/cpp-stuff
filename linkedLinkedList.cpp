#include<iostream>
using namespace std;

template<class T>
class Node {
public:
    T obj;
    Node* next;
    Node* prev;
};
template<typename T>
void printForward(Node<T>* head);

template<typename T>
void printReverse(Node<T>* head);
    
int main() {




    return 0;
}
template<typename T>
void printForward(Node<T>* head) {
    Node<T>* cur = head;
    if (cur == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        do {
            cout << cur->obj << endl;
            cur = cur->next;
        } while (cur != nullptr);
    }

}

template<typename T>
void printReverse(Node<T>* head) {
    Node<T>* cur = head;
    if (cur == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        //iterate to end;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cout << cur->obj << endl;
        while (cur->prev != nullptr) {
            cur = cur->prev;
            cout << cur->obj << endl;
        }
    }
}
