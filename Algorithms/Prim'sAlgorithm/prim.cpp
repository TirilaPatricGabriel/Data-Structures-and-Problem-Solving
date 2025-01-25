#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

class Comparator {
public:
    bool operator()(const pair<char, pair<char, int>>& p1, const pair<char, pair<char, int>>& p2) {
        return p1.second.second > p2.second.second;
    }
};

class Solution {
    unordered_map<char, vector<pair<char, int>>> adjacency_list;
    unordered_set<char> visited;
    vector<pair<char, pair<char, int>>> res;
    priority_queue<pair<char, pair<char, int>>, vector<pair<char, pair<char, int>>>, Comparator> edges_pq;
public:
    Solution(unordered_map<char, vector<pair<char, int>>> adjacency_list, unordered_set<char> visited) :
    adjacency_list(adjacency_list), visited(visited) {}

    void prim (char node) {
        this->visited.insert(node);

        for (const auto edge : this->adjacency_list[node]) {
            this->edges_pq.emplace(make_pair(node, make_pair(edge.first, edge.second)));
        }
        pair<char, pair<char, int>> next_best_edge = this->edges_pq.top();
        this->edges_pq.pop();

        while (this->visited.find(next_best_edge.second.first) != this->visited.end() && !this->edges_pq.empty()) {
            next_best_edge = this->edges_pq.top();
            this->edges_pq.pop();
        }

        if (this->visited.find(next_best_edge.second.first) == this->visited.end()){
            this->res.push_back(next_best_edge);
            this->prim(next_best_edge.second.first);
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