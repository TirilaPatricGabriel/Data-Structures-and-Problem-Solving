class Solution {
public:
    int characterReplacement(string s, int k) {

        int l = 0, r = 0, res = 0;
        unordered_map<char, int> freq = {};
        int maxn = 0;
        for (int r=0; r<s.size(); r++) {
            if (freq.find(s[r]) == freq.end()) {
                freq[s[r]] = 1;
            } else {
                freq[s[r]] += 1;
            }
            maxn = max(maxn, freq[s[r]]);

            while (r - l + 1 - maxn > k) {
                freq[s[l]]-=1;
                l += 1;
            }

            res = max(res, r - l + 1);
        }
        return res;

    }
};