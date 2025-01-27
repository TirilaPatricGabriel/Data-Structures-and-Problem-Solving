#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = nums1.size()-1;
        int i = m-1, j = n-1;
        while (i>=0 && j>=0) {
            if (nums1[i] > nums2[j]) {
                nums1[end] = nums1[i];
                i--;
            } else {
                nums1[end] = nums2[j];
                j--;
            }
            end--;
        }
        while (j>=0) {
            nums1[end] = nums2[j];
            j--;
            end--;
        }
    }
};

class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int j = 0, i = m; j<n; j++){
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(),nums1.end());
    }
};

class BadSolution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0, k=0;
        vector<int> v(m+n, -1);
        while (i<m && j<n) {
            if (nums1[i] < nums2[j]) {
                v[k++] = nums1[i];
                i++;
            } else {
                v[k++] = nums2[j];
                j++;
            }
        }

        while (i<m) {
            v[k++] = nums1[i];
            i++;
        }
        while (j<n) {
            v[k++] = nums2[j];
            j++;
        }

        nums1 = v;
    }
};



int main () {
    return 0;
}