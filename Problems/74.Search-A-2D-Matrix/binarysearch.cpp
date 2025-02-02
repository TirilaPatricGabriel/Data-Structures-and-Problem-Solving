#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchRow(vector<vector<int>>& matrix, int l, int r, int target) {
        if (l > r) return max(0, r); 

        int mid = (l + r) / 2;
        int elem = matrix[mid][0];

        if (elem == target || (mid + 1 < matrix.size() && matrix[mid][0] < target 
        && matrix[mid + 1][0] > target)) 
            return mid;

        if (target < elem) return searchRow(matrix, l, mid - 1, target);
        return searchRow(matrix, mid + 1, r, target);
    }

    bool binarySearch(vector<int>& arr, int l, int r, int target) {
        if (l > r) return false;  

        int mid = (l + r) / 2;
        int elem = arr[mid];

        if (target == elem) return true;
        if (target > elem) return binarySearch(arr, mid + 1, r, target);
        return binarySearch(arr, l, mid - 1, target);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false; 

        int minRow = 0, maxRow = matrix.size() - 1, minCol = 0, maxCol = matrix[0].size() - 1;

        int row = searchRow(matrix, minRow, maxRow, target);

        return binarySearch(matrix[row], minCol, maxCol, target);
    }
};


int main () {

    return 0;
}