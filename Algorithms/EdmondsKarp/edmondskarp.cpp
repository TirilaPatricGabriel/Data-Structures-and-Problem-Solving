#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

struct Edge {
    char node;
    int capacity, flow;

    Edge(char node, int capacity, int flow) : node(node), capacity(capacity), flow(flow) {}
};

class Solution {
    vector<vector<int>> capacity;
    unordered_map<char, vector<Edge>> adjacency_list;
public:
    Solution(vector<vector<int>> capacity) : capacity(capacity) {}

    char getNodeKey (int n) {
        switch (n) {
            case 0:
                return 'S';
            case 1:
                return 'A';
            case 2:
                return 'B';
            case 3:
                return 'C';
            case 4:
                return 'D';
            case 5:
                return 'T';
        }
    }

    void createAdjacencyList() {
        for (int i = 0; i < this->capacity.size(); i++) {
            char node1 = this->getNodeKey(i);
            for (int j = 0; j < this->capacity[i].size(); j++) {
                if (i != j) {
                    char node2 = this->getNodeKey(j);
                    Edge new_edge(node2, this->capacity[i][j], 0);
                    Edge reverse_edge(node1, 0, 0);
                    if (this->adjacency_list.find(node1) == this->adjacency_list.end()) {
                        this->adjacency_list[node1] = {new_edge};
                    } else {
                        this->adjacency_list[node1].push_back(new_edge);
                    }
                    if (this->adjacency_list.find(node2) == this->adjacency_list.end()) {
                        this->adjacency_list[node2] = {reverse_edge};
                    } else {
                        this->adjacency_list[node2].push_back(reverse_edge);
                    }
                }
            }
        }
    }

    void updatePath (unordered_map<char, char>& parent, int flow) {
        char child = 'T';
        while (parent[child] == 'S') {
        }
    }

    void EdmondsKarp() {
        while (true) {
            queue<pair<char, int>> nodesQ;
            unordered_map<char, char> parent;
            nodesQ.emplace(make_pair('S', INT_MAX));
            int maximum_flow_found = 0;

            while (!nodesQ.empty()) {
                pair<char, int> current = nodesQ.front();
                char currentNode = current.first;
                int value = current.second;
                nodesQ.pop();

                if (currentNode == 'T') {
                    maximum_flow_found = value;
                    this->updatePath(parent, maximum_flow_found);
                    continue;
                }

                for(auto& edge : this->adjacency_list[currentNode]) {
                    parent[edge.node] = currentNode;

                    int residual_cap = edge.capacity - edge.flow;
                    if (value > residual_cap) {
                        value = residual_cap;
                    }

                    nodesQ.emplace(make_pair(edge.node, value));
                }
            }

            if (maximum_flow_found == 0) break;
        }
    }

    void solution() {
        this->createAdjacencyList();
        this->EdmondsKarp();
    }
};

int main () {
    vector<vector<int>> capacity = {
            {0, 10, 5, 15, 0, 0},
            {0, 0, 0, 0, 15, 0},
            {0, 0, 0, 0, 10, 10},
            {0, 0, 0, 0, 0, 10},
            {0, 0, 0, 0, 0, 10},
            {0, 0, 0, 0, 0, 0}
    };

    Solution sol(capacity);
    sol.solution();
}