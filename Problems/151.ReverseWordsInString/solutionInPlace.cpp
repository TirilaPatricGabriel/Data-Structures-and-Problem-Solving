#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int r = s.size()-1, st = -1, e = -1;
        string res = "";
        while (r>=0) {
            while (r>=0 && s[r] == ' ') {
                r--;
            }
            if (r<0) {
                return res;
            }
            if (res.size() > 0) {
                res+=' ';
            }

            e = r;
            while (r>=0 && s[r] != ' ') {
                r--;
            }
            st = r;

            while (r < e) {
                r++;
                res += s[r];
            }
            r = st;
        }

        return res;
    }
};

int main () {

    return 0;
}