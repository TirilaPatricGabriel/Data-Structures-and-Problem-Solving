#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Comparator {
public:
    bool operator () (const pair<char, pair<char, int>>& edge1, const pair<char, pair<char, int>>& edge2) {
        return edge1.second.second > edge2.second.second;
    }
};

class UnionFind {
    unordered_map<char, char> parent;
    unordered_map<char, int> rank;
public:
    UnionFind(const unordered_set<char>& nodes) {
        for (const char& node : nodes) {
            this->parent[node] = node;
            this->rank[node] = 0;
        }
    }

    char findRoot(char node) {
        if (node != this->parent[node]){
            this->parent[node] = this->findRoot(this->parent[node]);
        }
        return this->parent[node];
    }

    void unionOfTrees(char node1, char node2) {
        char root1 = this->findRoot(node1);
        char root2 = this->findRoot(node2);
        int rank1 = this->rank[root1], rank2 = this->rank[root2];

        if (rank1 > rank2) {
            this->parent[root2] = root1;
        } else if (rank2 > rank1) {
            this->parent[root1] = root2;
        } else {
            this->parent[root2] = root1;
            rank[root1] += 1;
        }
    }
};

class Solution {
    unordered_map<char, vector<pair<char, int>>> adjacency_list;
    priority_queue<pair<char, pair<char, int>>, vector<pair<char, pair<char, int>>>, Comparator> edges_pq;
    unique_ptr<UnionFind> uf;
    unordered_set<char> allNodes;
    vector<pair<char, pair<char, int>>> res;
public:
    Solution (unordered_map<char, vector<pair<char, int>>> adjacency_list) : adjacency_list(adjacency_list) {};

    void constructPQ() {
        for (const auto& line : this->adjacency_list) {
            char node = line.first;
            for (const auto& edge : line.second) {
                if (node < edge.first) {
                    this->edges_pq.emplace(make_pair(node, edge));
                }
            }
        }
    }

    void createUnionFindObject() {
        for (const auto& pair : this->adjacency_list) {
            allNodes.emplace(pair.first);
        }
        uf = make_unique<UnionFind>(allNodes);
    }

    void kruskal () {
        pair<char, pair<char, int>> edge;

        while (!this->edges_pq.empty()) {
            edge = this->edges_pq.top();
            this->edges_pq.pop();
            if (this->uf->findRoot(edge.first) != this->uf->findRoot(edge.second.first)) {
                res.push_back(edge);
                this->uf->unionOfTrees(edge.first, edge.second.first);
            }
        }
    }

    vector<pair<char, pair<char, int>>> solution (){
        this->constructPQ();
        this->createUnionFindObject();
        this->kruskal();

        return this->res;
    }
};

int main () {
    unordered_map<char, vector<pair<char, int>>> adjacency_list = {
            {'A', {{'B', 2}, {'C', 3}, {'D', 3}}},
            {'B', {{'A', 2}, {'C', 4}, {'E', 3}}},
            {'C', {{'A', 3}, {'B', 4}, {'E', 1}, {'F', 6}, {'D', 5}}},
            {'D', {{'A', 3}, {'C', 5}, {'F', 7}}},
            {'E', {{'B', 3}, {'C', 1}, {'F', 8}}},
            {'F', {{'C', 6}, {'E', 8}, {'D', 7}, {'G', 9}}},
            {'G', {{'F', 9}}}
    };

    Solution* sol = new Solution(adjacency_list);

    vector<pair<char, pair<char, int>>> res = sol->solution();

    for (const auto& edge : res) {
        char first_node = edge.first;
        char second_node = edge.second.first;
        int distance = edge.second.second;

        cout<<first_node<<" - "<<second_node<<" = "<<distance<<endl;
    }
}