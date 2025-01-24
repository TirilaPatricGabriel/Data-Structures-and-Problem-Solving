#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
    unordered_map<char, vector<pair<char,int>>> adjacency_list;
    unordered_map<char, int> node_distances;
    vector<char> nodes;
    int size;
public:
    Solution(unordered_map<char, vector<pair<char,int>>> adjacency_list,
             unordered_map<char, int> node_distances, vector<char> nodes) : adjacency_list(adjacency_list),
             node_distances(node_distances), size(nodes.size()) { this->nodes = nodes; }

    void calculate_neighbors(char node) {
        for (pair<char, int> neighbor : this->adjacency_list[node]) {
            char key = neighbor.first;
            int distance = neighbor.second;

            if (this->node_distances[node] + distance < this->node_distances[key]) {
                this->node_distances[key] = this->node_distances[node] + distance;
            }
        }
    }

    void bellman_ford() {
        int i = 1;
        while (i < this->size) {
            for (const auto& node : this->nodes) {
                if (this->node_distances[node] != INT_MAX) {
                    this->calculate_neighbors(node);
                }
            }
            i+=1;
        }
    }

    unordered_map<char, int> start(char node) {
        this->node_distances[node] = 0;
        this->bellman_ford();
        return this->node_distances;
    }
};

int main () {
    unordered_map<char, vector<pair<char,int>>> adjacency_list = {
            {'A', {{'B', 7}, {'E', 1}}},
            {'B', {{'C', 3}, {'E', 8}, {'E', 7}}},
            {'C', {{'B', 3}, {'E', 2}, {'D', 6}}},
            {'D', {{'C', 6}, {'E', 7}}},
            {'E', {{'A', 1}, {'B', 8}, {'C', 2}, {'D', 7}}},
    };

    unordered_map<char, int> node_distances = {
            {'A', INT_MAX},
            {'B', INT_MAX},
            {'C', INT_MAX},
            {'D', INT_MAX},
            {'E', INT_MAX}
    };

    vector<char> nodes = {
            'A', 'B', 'C', 'D', 'E'
    };

    Solution* sol = new Solution(adjacency_list, node_distances, nodes);
    unordered_map<char, int> res = sol->start(nodes[0]);

    for (const auto& pair : res) {
        cout<<pair.first<<" "<<pair.second<<endl;
    }
    return 0;
}