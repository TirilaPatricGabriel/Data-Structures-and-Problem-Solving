#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        string str_x = to_string(x);
        int i = 0, j = str_x.size()-1;

        while (i < j) {
            if (str_x[i] != str_x[j]) {
                return false;
            }
            i += 1;
            j -= 1;
        }
        return true;
    }
};

class SolutionWithoutStrings {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long int div = 1;
        while (div * 10 <= x) {
            div *= 10;
        }

        while (x && div > 0) {
            int r = x % 10;
            int l = (x / div) % 10;
            if (r != l) {
                return false;
            }
            x /= 10;
            div /= 100;
        }
        return true;
    }
};

int main () {
    SolutionWithoutStrings sol;
    cout<<sol.isPalindrome(11);
}