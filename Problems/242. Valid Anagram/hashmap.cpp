#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> charsMap = {};

        for(int i=0; i<s.size(); i++) {
            if (charsMap.find(s[i]) == charsMap.end()) charsMap[s[i]] = 1;
            else charsMap[s[i]]++;
        }

        for (int j=0; j<t.size(); j++) {
            if (charsMap.find(t[j]) == charsMap.end() || charsMap[t[j]] == 0) return false;
            charsMap[t[j]]--;
        }

        return true;
    }
};

int main () {

    return 0;
}