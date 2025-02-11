#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            if (magazine.size() < ransomNote.size()) return false;
    
            unordered_map<char, int> letters = {};
    
            for (int i=0; i<magazine.size(); i++) {
                if (letters.find(magazine[i]) == letters.end()) {
                    letters[magazine[i]] = 1;
                } else {
                    letters[magazine[i]] += 1;
                }
            }
    
            for (int i=0; i<ransomNote.size(); i++) {
                if (letters.find(ransomNote[i]) == letters.end() || letters[ransomNote[i]] <= 0)
                    return false;
                letters[ransomNote[i]] -= 1;
            }
            return true;
        }
    };

int main () {

    return 0;
}