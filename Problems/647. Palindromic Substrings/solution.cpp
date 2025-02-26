#include <string>

using namespace std;

class Solution {
public:
    int expandAroundCenter(string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int totalCount = 0;
        for (int i = 0; i < s.size(); i++) {
            totalCount += expandAroundCenter(s, i, i);
            totalCount += expandAroundCenter(s, i, i + 1);
        }
        return totalCount;
    }
};