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
    unordered_map<char, vector<Edge>> list;
public:
    Solution(vector<vector<int>> capacity) : capacity(capacity) {}

    char getNodeKey (int i) {
        switch (i){
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

    void createResidualGraph () {
        for (int i = 0; i < this->capacity.size(); i++) {
            char node1 = this->getNodeKey(i);
            for (int j = 0; j < this->capacity[i].size(); j++) {
                char node2 = this->getNodeKey(j);

                if (node1 != node2) {
                    Edge new_edge(node2, this->capacity[i][j], 0);
                    if (this->list.find(node1) == this->list.end()) {
                        this->list[node1] = {new_edge};
                    } else {
                        this->list[node1].push_back(new_edge);
                    }

                    Edge residual_edge(node1, 0, 0);
                    if (this->list.find(node2) == this->list.end()) {
                        this->list[node2] = {residual_edge};
                    } else {
                        this->list[node2].push_back(residual_edge);
                    }
                }

            }
        }
    }

    int dfs(char node, int bottleneck, unordered_set<char>& visited) {
        if (visited.find(node) != visited.end()) {
            return 0;
        }
        if (node == 'T') {
            return bottleneck;
        }

        visited.emplace(node);

        int flow = 0;
        for (auto& edge : this->list[node]) {
            int residual_capacity = edge.capacity - edge.flow;

            if (residual_capacity > 0) {
                if (bottleneck > residual_capacity) {
                    bottleneck = residual_capacity;
                }
                flow = dfs(edge.node, bottleneck, visited);
                edge.flow = edge.flow + flow;

                for (int i=0; i<this->list[edge.node].size(); i++) {
                    if (this->list[edge.node][i].node == node) {
                        this->list[edge.node][i].flow = this->list[edge.node][i].flow - flow;
                    }
                }

                if (node == 'S') {
                    return flow;
                }
            }
        }

        return flow;
    }

    int FordFulkerson() {
        int max_flow = 0;

        while (true) {
            unordered_set<char> visited;
            int flow = this->dfs('S', INT_MAX, visited);
            max_flow += flow;

            if (flow == 0) {
                return max_flow;
            }
        }
    }

    int solution () {
        this->createResidualGraph();
        return this->FordFulkerson();
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
    cout<<sol.solution();
}