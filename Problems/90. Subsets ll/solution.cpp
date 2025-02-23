class Solution {
    public:
        void createSubsets(int idx, vector<vector<int>>& subsets, unordered_map<int, bool>& visited, vector<int>& currentSubset, vector<int>& nums){
            
            unordered_map<int, bool> used = {};
            for(int i=idx+1; i<nums.size(); i++) {
                if ((visited.find(i) == visited.end() || visited[i] == false) && used.find(nums[i]) == used.end()){
                    currentSubset.push_back(nums[i]);
                    subsets.push_back(currentSubset);
                    visited[i] = true;
                    createSubsets(i, subsets, visited, currentSubset, nums);
                    used[nums[i]] = true;
                    visited[i] = false;
                    currentSubset.pop_back();
                }
            }
            
        }
    
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> subsets = {{}};
            vector<int> currentSubset = {};
            unordered_map<int, bool> visited = {};
            createSubsets(-1, subsets, visited, currentSubset, nums);
    
            return subsets;
    
        }
    };