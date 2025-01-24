#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

unordered_map<char, vector<pair<char,int>>> adjacency_list = {
        {'A', {{'B', 7}, {'E', 1}}},
        {'B', {{'C', 3}, {'E', 8}, {'E', 7}}},
        {'C', {{'B', 3}, {'E', 2}, {'D', 6}}},
        {'D', {{'C', 6}, {'E', 7}}},
        {'E', {{'A', 1}, {'B', 8}, {'C', 2}, {'D', 7}}},
};
unordered_set<char> visited = {};

unordered_map<char, int> nodes = {
        {'A', INT_MAX},
        {'B', INT_MAX},
        {'C', INT_MAX},
        {'D', INT_MAX},
        {'E', INT_MAX}
};

struct Comparator {
    bool operator()(const pair<char, int>& p1, const pair<char, int>& p2) {
        return p1.second > p2.second;
    }
};

class Solution {
    priority_queue<pair<char, int>, vector<pair<char, int>>, Comparator> nodes_pq;
public:
    void insertIntoPQ (pair<char, int> node) {
        this->nodes_pq.push(node);
    }

    void getSmallestDistanceToNeighbors(pair<char, int> node) {
        visited.insert(node.first);
        vector<pair<char, int>> neighbors = adjacency_list[node.first];

        int i;
        for (i = 0; i < neighbors.size(); i++) {
            char neighborNode = neighbors[i].first;
            int distance = neighbors[i].second;
            int newDistance = node.second + distance;
            if (visited.find(neighborNode) == visited.end() && newDistance < nodes[neighborNode]) {
                nodes[neighborNode] = newDistance;
                this->nodes_pq.emplace(neighborNode, newDistance);
            }
        }
    }

    void cycleThroughNodes() {
        pair<char, int> nextNode = this->nodes_pq.top();
        this->nodes_pq.pop();
        this->getSmallestDistanceToNeighbors(nextNode);
    }

    void solution () {
        while (!this->nodes_pq.empty()) {
            this->cycleThroughNodes();
        }
    }

};

int main () {
    Solution sol;
    nodes['A'] = 0;
    sol.insertIntoPQ({'A', 0});

    sol.solution();

    for (const auto& pair : nodes) {
        cout<<pair.first<<" "<<pair.second<<endl;
    }

    return 0;
}