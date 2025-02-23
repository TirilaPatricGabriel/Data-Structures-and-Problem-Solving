class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            if (s1.size() > s2.size()) return false;
            unordered_map<char, int> s1map, s2map;
    
            for (int i=0; i<s1.size(); i++){
                char c1 = s1[i]; char c2 = s2[i];
                if (s1map.find(c1) == s1map.end()) {
                    s1map[c1] = 1;
                } else {
                    s1map[c1] += 1;
                }
    
                if (s2map.find(c2) == s2map.end()) {
                    s2map[c2] = 1;
                } else {
                    s2map[c2] += 1;
                }
            }
            
            int matches = 0;
            for (char letter = 'a'; letter <= 'z'; letter++) {
                if (s1map.find(letter) == s1map.end()) {
                    s1map[letter] = 0;
                } 
                if (s2map.find(letter) == s2map.end()) {
                    s2map[letter] = 0;
                }
                if (s1map[letter] == s2map[letter]) {
                    matches += 1;
                }
            }
    
            if (matches == 26) return true;
    
            for (int i=s1.size(); i<s2.size(); i++) {
                if (matches == 26) return true;
                char c1 = s2[i], c2 = s2[i-s1.size()];
                s2map[c1]+=1;
                s2map[c2]-=1; 
    
                if (c1 != c2) {
                    if (s1map[c1] == s2map[c1]) matches++;
                    else if (s1map[c1] == s2map[c1] - 1) matches--;
    
                    if (matches == 26) return true;
    
                    if (s1map[c2] == s2map[c2]) matches++;
                    else if (s1map[c2] == s2map[c2] + 1) matches--;
                    
                    if (matches == 26) return true;
                }
            }
            
            return false;
    
        }
    };