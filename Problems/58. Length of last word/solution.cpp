#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1, start = -1;
        for (int i=n; i>=0; i--) {
            if (s[i] != ' ' && start == -1) {
                start = i;
            }
            if ((s[i] == ' ' || i == 0) && start != -1) {
                if (start == i) return 1;
                if (i == 0 && s[i] != ' ') return start-i+1;
                return start-i;
            }
        }
        return 0;
    }
};

int main () {

    return 0;
}