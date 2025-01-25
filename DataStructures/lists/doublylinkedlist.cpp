#include <iostream>

using namespace std;

class Node {
private:
    int value;
    Node *next, *prev;
public:
    Node(int value) : value(value), next(nullptr), prev(nullptr) {}

    void setNext(Node* node) {
        this->next = node;
    }
    void setPrev(Node* node) {
        this->prev = node;
    }
    Node* getPrev() {
        return this->prev;
    }
    Node* getNext() {
        return this->next;
    }
    void setVal(int value) {
        this->value = value;
    }
    int getVal(){
        return this->value;
    }
};

class DoublyLinkedList {
private:
    Node *head, *tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void prepend(int value) {
        Node *newNode = new Node(value);

        if (this->head == nullptr) {
            this->head = this->tail = newNode;
        } else {
            this->head->setPrev(newNode);
            newNode->setNext(this->head);
            this->head = newNode;
        }
    }

    void append(int value) {
        Node* newNode = new Node(value);

        if (this->head==nullptr) {
            this->head = this->tail = newNode;
        } else {
            this->tail->setNext(newNode);
            newNode->setPrev(this->tail);
            this->tail = newNode;
        }
    }

    ~DoublyLinkedList() {
        if (head != nullptr) {
            Node *curr = this->head;
            while (curr != nullptr) {
                Node* temp = curr->getNext();
                delete curr;
                curr = temp;
            }
        }
        head = tail = nullptr;
    }

    void printListLeftToRight () {
        Node* curr = head;

        while (curr != nullptr) {
            cout<<curr->getVal()<<" -> ";
            curr = curr->getNext();
        }
        cout<<"nullptr"<<endl;
    }

    void printListRightToLeft () {
        Node* curr = tail;
        while (curr != nullptr) {
            cout<<curr->getVal()<<" -> ";
            curr = curr->getPrev();
        }
        cout<<"nullptr"<<endl;
    }
};

int main () {
    DoublyLinkedList list;

    list.append(2);
    list.append(4);
    list.append(6);
    list.prepend(8);
    list.printListLeftToRight();
    list.printListRightToLeft();
}