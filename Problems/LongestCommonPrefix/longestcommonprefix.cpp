#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string firstWord = strs[0];
        string prefix = "";
        for (int i=0; i<firstWord.size(); i++) {
            for (int j=1; j<strs.size(); j++) {
                if (strs[j][i] != firstWord[i]) {
                    return prefix;
                }
            }
            prefix += firstWord[i];
        }
        return prefix;
    }
};

int main () {

    return 0;
}