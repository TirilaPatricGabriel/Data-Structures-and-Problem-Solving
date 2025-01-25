#include <iostream>
using namespace std;

class Node {
private:
    int value;
    Node* next;
public:
    Node(int value) : value(value), next(nullptr) {}

    int getValue() const {
        return value;
    }

    void setValue(int value) {
        this->value = value;
    }

    void setNextNode(Node* node) {
        this->next = node;
    }

    Node* getNextNode() const {
        return this->next;
    }
};

class List {
private:
    Node* head;
public:
    List() : head(nullptr) {}

    Node* getHead() const {
        return this->head;
    }

    void setHead(Node* node) {
        this->head = node;
    }

    ~List() {
        Node* curr = this->head;
        while (curr != nullptr) {
            Node* temp = curr->getNextNode();
            delete curr;
            curr = temp;
        }
        this->head = nullptr;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (this->head == nullptr) {
            this->head = newNode;
            return;
        }

        Node* curr = this->head;
        while (curr->getNextNode() != nullptr) {
            curr = curr->getNextNode();
        }
        curr->setNextNode(newNode);
    }

    void prepend(int value) {
        Node* prependNode = new Node(value);
        prependNode->setNextNode(this->head);
        this->head = prependNode;
    }
};

int main() {
    List myList;

    myList.append(10);
    myList.append(20);
    myList.append(30);

    Node* curr = myList.getHead();
    while (curr != nullptr) {
        cout << curr->getValue() << " -> ";
        curr = curr->getNextNode();
    }
    cout << "nullptr" << endl;

    return 0;
}
