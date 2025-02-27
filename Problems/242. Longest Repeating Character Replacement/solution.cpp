class Solution {
public:
    int getMax(unordered_map<char, int> freq) {
        int max = 0;
        for (auto& pair : freq) {
            if (max < pair.second) {
                max = pair.second;
            }
        }
        return max;
    }

    int characterReplacement(string s, int k) {

        int l = 0, r = 0, res = 0;
        unordered_map<char, int> freq = {};
        for (int r=0; r<s.size(); r++) {
            if (freq.find(s[r]) == freq.end()) {
                freq[s[r]] = 1;
            } else {
                freq[s[r]] += 1;
            }

            while (r - l + 1 - getMax(freq) > k) {
                freq[s[l]]-=1;
                l += 1;
            }

            res = max(res, r - l + 1);
        }
        return res;

    }
};