#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <unordered_set>
#include <memory>

using namespace std;


struct Edge {
    int node1, node2, weight;
    Edge(int node1, int node2, int weight) : node1(node1), node2(node2), weight(weight) {};
    bool operator==(const Edge& other) const {
        return (node1 == other.node1 && node2 == other.node2 && weight == other.weight) ||
               (node1 == other.node2 && node2 == other.node1 && weight == other.weight);
    }
};

struct EdgeHash {
    size_t operator()(const Edge& edge) const {
        return hash<int>()(edge.node1) ^ hash<int>()(edge.node2) ^ hash<int>()(edge.weight);
    }
};

class Comparator {
public:
    bool operator () (const Edge& edge1, const Edge& edge2) {
        return edge1.weight > edge2.weight;
    }
};

class UnionFind {
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
public:
    UnionFind(int numberOfNodes) {
        for (int i=0; i<numberOfNodes; i++) {
            this->parent[i] = i;
            this->rank[i] = 0;
        }
    }

    int find (int node) {
        if (node != parent[node]) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    void unionMethod (int node1, int node2) {
        int rank1 = this->rank[node1], rank2 = this->rank[node2];

        if (rank1 > rank2) {
            this->parent[node2] = node1;
        } else if (rank2 > rank1) {
            this->parent[node1] = node2;
        } else {
            this->parent[node2] = node1;
            this->rank[node1]++;
        }
    }
};

class Solution {
    vector<vector<int>> graph;
    priority_queue<Edge, vector<Edge>, Comparator> edges_pq;
    unordered_set<Edge, EdgeHash> allEdges;
    unique_ptr<UnionFind> uf;
    vector<Edge> res;
public:
    Solution(vector<vector<int>> graph) : graph(graph) {}

    void createAllEdges() {
        for (int i=0; i<this->graph.size(); i++) {
            for (int j=0; j<this->graph.size(); j++) {
                if (this->graph[i][j] > 0) {
                    Edge new_edge(i, j, this->graph[i][j]);
                    this->allEdges.emplace(new_edge);
                }
            }
        }
    }

    void createEdgesPQ() {
        this->createAllEdges();
        for (const Edge& edge : this->allEdges) {
            edges_pq.emplace(edge);
        }
    }

    void Kruskal () {
        while (!edges_pq.empty()) {
            Edge new_edge = edges_pq.top();
            edges_pq.pop();

            if (this->uf->find(new_edge.node1) != this->uf->find(new_edge.node2)) {
                this->res.push_back(new_edge);
                this->uf->unionMethod(new_edge.node1, new_edge.node2);
            }
        }
    }

    vector<Edge> start () {
        this->uf = make_unique<UnionFind>(this->graph.size());
        this->createEdgesPQ();
        this->Kruskal();
        return this->res;
    }
};

int main () {
    vector<vector<int>> graph = {
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}
    };

    Solution sol(graph);
    vector<Edge> res = sol.start();

    for (const Edge& edge : res) {
        cout<<edge.node1<<" - "<<edge.node2<<" = "<<edge.weight<<endl;
    }
}