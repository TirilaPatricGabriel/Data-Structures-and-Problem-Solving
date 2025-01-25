#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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
    Solution(vector<vector<int>>& capacity) : capacity(capacity) {}

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
                    Edge reverse_edge(node1, 0, 0); // Add reverse edge with 0 capacity
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


    void updateResidualEdge (char node1, char node2, int flow_to_add) {
        if (this->adjacency_list.find(node1) == this->adjacency_list.end()) {
            Edge residual_edge(node2, 0, -flow_to_add);
            this->adjacency_list[node1] = {residual_edge};
        } else {
            for (auto& residual_edge : this->adjacency_list[node1]) {
                if (residual_edge.node == node2) {
                    residual_edge.flow = residual_edge.flow - flow_to_add;
                    break;
                }
            }
        }
    }

    int dfs(char node, int bottle_neck, unordered_set<char>& visited) {
        if (visited.find(node) != visited.end()) {
            return 0;
        }
        if (node == 'T') {
            return bottle_neck;
        }

        visited.emplace(node);

        for (auto& edge : this->adjacency_list[node]) {
            int residual_capacity = edge.capacity - edge.flow;

            if (residual_capacity > 0 && visited.find(edge.node) == visited.end()) {
                int new_bottleneck = min(bottle_neck, residual_capacity);
                int flow_to_add = dfs(edge.node, new_bottleneck, visited);

                if (flow_to_add > 0) {
                    edge.flow += flow_to_add;
                    this->updateResidualEdge(edge.node, node, flow_to_add);
                    return flow_to_add;
                }
            }
        }
        return 0;
    }


    void FordFulkerson() {
        int max_flow = 0;

        while (true) {
            unordered_set<char> visited;
            int flow_to_add = this->dfs('S', INT_MAX, visited);

            if (flow_to_add == 0) {
                break;
            }

            max_flow += flow_to_add;
        }

        cout<<"Maximum Flow: "<<max_flow<<endl;
    }

    void solution () {
        this->createAdjacencyList();
        this->FordFulkerson();
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