#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1) return true;
        int l = 0, r = s.size()-1;

        while (l < r) {
            while (!isalpha(s[l]) && !isdigit(s[l]) && l < r) l++;
            while (!isalpha(s[r]) && !isdigit(s[r]) && l < r) r--;

            if ((s[l] != s[r] && tolower(s[l]) != tolower(s[r]))) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};

int main () {
    return 0;
}