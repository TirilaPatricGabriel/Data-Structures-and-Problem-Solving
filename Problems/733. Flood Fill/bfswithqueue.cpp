#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (color == image[sr][sc]) return image;
        queue<pair<int, int>> q;
        q.emplace(make_pair(sr, sc));

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int oldColor = image[sr][sc];

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            int row = p.first;
            int col = p.second;

            image[row][col] = color;

            for (auto& dir : dirs) {
                int i = dir[0], j = dir[1];
                int newRow = row + i, newCol = col + j;

                if (newRow < image.size() && newRow >= 0 && newCol < image[0].size() && newCol >= 0 && image[newRow][newCol] == oldColor) {
                    q.emplace(make_pair(newRow, newCol));
                }
            }
        }

        return image;
    }
};

int main () {

    return 0;
}