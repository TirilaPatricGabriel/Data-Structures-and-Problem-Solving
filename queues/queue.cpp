#include <iostream>

using namespace std;

class Queue {
private:
    int *end, *start;
    int array[10];
public:
    Queue() : end(&this->array[0]), start(&this->array[0]) {}

    void push (int value) {
        if (this->end == this->start-1) {
            cout<<"Queue is full! Can't add anymore values"<<endl;
            return;
        }
        if (this->end == &array[9]) {
            if (this->start != &array[0]) {
                *this->end = value;
                this->end = &array[0];
                return;
            } else {
                cout<<"Queue is full! Can't add anymore values"<<endl;
                return;
            }
        }
        *this->end = value;
        this->end++;
    }

    int pop () {
        if (this->start == this->end) {
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        int res = *this->start;
        if (this->start == &array[9]) {
            this->start = &array[0];
        }
        this->start++;

        return res;
    }
};

int main () {
    Queue q;
    q.push(10);
    q.push(5);
    q.pop();
    q.push(15);
    q.push(25);
    q.pop();
    q.pop();
    q.pop();
    q.push(35);
    q.push(45);
    q.push(55);
    q.pop();
    q.push(65);
    q.push(65);
    q.push(65);
    q.push(65);
    q.push(65);
    q.push(65);
    q.push(65);
    q.push(65);

    cout<<q.pop()<<" "<<q.pop();
}