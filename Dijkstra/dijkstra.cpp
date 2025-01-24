#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_map<char, vector<pair<char,int>>> adjacency_list = {
        {'A', {{'B', 7}, {'E', 1}}},
        {'B', {{'C', 3}, {'E', 8}, {'E', 7}}},
        {'C', {{'B', 3}, {'E', 2}, {'D', 6}}},
        {'D', {{'C', 6}, {'E', 7}}},
        {'E', {{'A', 1}, {'B', 8}, {'C', 2}, {'D', 7}}},
};
unordered_map<char, int> nodes = {
        {'A', INT_MAX},
        {'B', INT_MAX},
        {'C', INT_MAX},
        {'D', INT_MAX},
        {'E', INT_MAX}
};
unordered_set<char> visited = {};

class Solution {
public:
    void getSmallestDistanceToNeighbors(char node) {
        visited.insert(node);
        vector<pair<char, int>> neighbors = adjacency_list[node];

        int i;
        for (i = 0; i < neighbors.size(); i++) {
            char neighborNode = neighbors[i].first;
            int distance = neighbors[i].second;
            if (nodes[node] + distance < nodes[neighborNode]) {
                nodes[neighborNode] = nodes[node] + distance;
            }
        }
    }

    void cycleThroughNodes() {
        int min = INT_MAX;
        char nextNode;

        for (const auto& node : nodes) {
            if (min > node.second && visited.find(node.first) == visited.end()) {
                min = node.second;
                nextNode = node.first;
            }
        }
        this->getSmallestDistanceToNeighbors(nextNode);
    }

    void solution () {
        for (int i=0; i<adjacency_list.size(); i++) {
            this->cycleThroughNodes();
        }
    }

};

int main () {
    Solution sol;
    nodes['A'] = 0;

    sol.solution();

    for (const auto& pair : nodes) {
        cout<<pair.first<<" "<<pair.second<<endl;
    }

    return 0;
}