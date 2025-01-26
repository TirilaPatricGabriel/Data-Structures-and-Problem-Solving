#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

struct Edge {
    int node, capacity, flow;
    Edge(int node, int capacity, int flow) : node(node), capacity(capacity), flow(flow) {}
};

class Solution {
    unordered_map<int, vector<Edge>> list;
    int size;
public:
    void createAdjacencyList (vector<vector<int>>& capacity) {
        this->size = capacity.size();
        for (int i=0; i<capacity.size(); i++) {
            for (int j=0; j<capacity[i].size(); j++) {
                if (i != j && capacity[i][j] > 0) {
                    Edge newEdge(j, capacity[i][j], 0);
                    Edge residualEdge(i, 0, 0);
                    if (this->list.find(i) == this->list.end()) {
                        this->list[i] = {newEdge};
                    } else {
                        this->list[i].push_back(newEdge);
                    }

                    if (this->list.find(j) == this->list.end()) {
                        this->list[j] = {residualEdge};
                    } else {
                        this->list[j].push_back(residualEdge);
                    }
                }
            }
        }
    }

    int EdmondsKarp () {

        int max_flow = 0;
        while (true) {
            int flow = 0;

            vector<int> parent(this->size, -1);
            unordered_set<int> visited;

            queue<pair<int, int>> q;
            q.emplace(0, INT_MAX);
            while (!q.empty()) {
                int node = q.front().first;
                int bottleneck = q.front().second;
                q.pop();
                visited.emplace(node);

                if (node == this->size-1) {
                    flow = bottleneck;
                    break;
                }

                for (const Edge& edge : this->list[node]) {
                    int residual_capacity = edge.capacity - edge.flow;
                    if (residual_capacity > 0 && visited.find(edge.node) == visited.end()) {
                        if (bottleneck > residual_capacity) {
                            bottleneck = residual_capacity;
                        }
                        parent[edge.node] = node;
                        q.emplace(edge.node, bottleneck);
                    }
                }
            }

            // augmenting paths

            int node = this->size-1;
            int p = parent[node];
            while (p != -1) {
                for (Edge& edge : this->list[p]) {
                    if (edge.node == node) {
                        edge.flow += flow;
                    }
                }

                for (Edge& edge : this->list[node]) {
                    if (edge.node == p) {
                        edge.flow -= flow;
                    }
                }

                node = p;
                p = parent[node];
            }

            max_flow += flow;
            if (flow == 0) break;
        }

        return max_flow;
    }

    int solution (vector<vector<int>>& capacity) {
        this->createAdjacencyList(capacity);
        return this->EdmondsKarp();
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

    Solution sol;
    cout<<sol.solution(capacity);
}