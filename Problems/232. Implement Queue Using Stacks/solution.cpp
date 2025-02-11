#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> st1, st2;
public:
    MyQueue() {}
    
    void push(int x) {
        this->st1.push(x);
    }
    
    int pop() {
        if (!this->st2.empty()) {
            int i = this->st2.top();
            this->st2.pop();
            return i;
        }

        while (!this->st1.empty()) {
            int i = this->st1.top();
            this->st1.pop();
            this->st2.push(i);
        }
        return pop();
    }
    
    int peek() {
        if (!this->st2.empty()) {
            return this->st2.top();
        }

        while (!this->st1.empty()) {
            int i = this->st1.top();
            this->st1.pop();
            this->st2.push(i);
        }

        return peek();
    }
    
    bool empty() {
        return this->st1.empty() && this->st2.empty();
    }
};

int main () {

    return 0;
}