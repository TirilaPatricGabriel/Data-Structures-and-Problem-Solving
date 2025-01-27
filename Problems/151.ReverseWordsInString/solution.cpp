#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i=0, n=0;
        unordered_map<int, string> words;
        string word = "";
        bool inWord = 0;
        while (i < s.size()) {
            if (s[i] != ' ') {
                inWord = 1;
            } else {
                inWord = 0;
                if (word.size() > 0) {
                    words[n] = word;
                    n++;
                }
                word = "";
            }
            if (inWord) {
                word += s[i];
            }
            i++;
        }
        if (word.size() > 0) {
            words[n] = word;
        } else n--;

        s = "";
        while (n>=1) {
            s += words[n];
            s += ' ';
            n--;
        }
        s += words[0];
        return s;
    }
};

int main () {
    return 0;
}