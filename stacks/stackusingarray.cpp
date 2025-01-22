#include <iostream>

using namespace std;

class Stack {
private:
    int *end;
    int array[10];
public:
    Stack () : end(nullptr) {}

    void push(int value){
        if (this->end == nullptr) {
            array[0] = value;
            this->end = &array[0];
        } else {
            if (this->end == &array[9]) {
                cout<<"Stack is full!"<<endl;
                return;
            } else {
                this->end++;
                *this->end = value;
            }
        }
    }
    int pop(){
        int poppedValue;

        if (this->end == nullptr) {
            cout<<"The stack is empty!"<<endl;
            return -1;
        }

        poppedValue = *this->end;
        if (this->end == &array[0]) {
            this->end = nullptr;
        } else {
            this->end--;
        }

        return poppedValue;
    }
    bool isEmpty() const {
        return this->end == nullptr ? true : false;
    }
};

int main () {
    Stack st;

    st.push(5);
    st.push(10);
    st.push(-15);

    int val = st.pop();

    cout<<val<<endl;
}