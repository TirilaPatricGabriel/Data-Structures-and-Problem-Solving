#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stck = {};

        int i, n = s.size();
        for (i = 0; i<s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stck.push(s[i]);
            } else {
                if (stck.size() <= 0) return false;
                char c = stck.top();
                stck.pop();
                switch (s[i]) {
                    case '}':
                        if (c != '{') {
                            return false;
                        }
                        break;
                    case ']':
                        if (c != '[') {
                            return false;
                        }
                        break;
                    case ')':
                        if (c != '(') {
                            return false;
                        }
                        break;
                }
            }
        }

        return stck.size() > 0 ? false : true;
    }
};

int main () {

}