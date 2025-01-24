#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
    unordered_map<char, vector<pair<char, int>>> adjacency_list;
    unordered_set<char> visited;
    vector<pair<char, pair<char, int>>> res;
public:
    Solution(unordered_map<char, vector<pair<char, int>>> adjacency_list, unordered_set<char> visited) :
    adjacency_list(adjacency_list), visited(visited) {}

    void prim (char node) {
        this->visited.insert(node);
        int min = INT_MAX;
        pair<char, pair<char, int>> next_best_edge = {'0', {'0', INT_MAX}};
        for (char visited_node : this->visited) {
            for (const auto& pair : adjacency_list[visited_node]) {
                if (this->visited.find(pair.first) == this->visited.end() && min > pair.second) {
                    min = pair.second;
                    next_best_edge = {visited_node, {pair.first, pair.second}};
                }
            }
        }
        char nextNode = next_best_edge.second.first;
        if (nextNode != '0'){
            this->res.push_back(next_best_edge);
            this->prim(nextNode);
        }
    }

    vector<pair<char, pair<char, int>>> start(char node) {
        this->prim(node);
        return this->res;
    }
};

int main () {
        unordered_map<char, vector<pair<char, int>>> adjacency_list = {
                {'A', {{'B', 2}, {'C', 3}, {'D', 3}},},
                {'B', {{'A', 2}, {'C', 4}, {'E', 3}},},
                {'C', {{'A', 3}, {'B', 4}, {'E', 1}, {'F', 6}, {'D', 5}},},
                {'D', {{'A', 3}, {'C', 5}, {'F', 7}},},
                {'E', {{'B', 3}, {'C', 1}, {'F', 8}},},
                {'F', {{'C', 6}, {'E', 8}, {'D', 7}, {'G', 9}},},
                {'G', {{'F', 9}}},
        };

        Solution* sol = new Solution(adjacency_list, {});
        vector<pair<char, pair<char, int>>> res = sol->start('A');

        for(const auto& pair : res) {
            cout<<pair.first<<" -> "<<pair.second.first<<" = "<<pair.second.second<<endl;
        }
}