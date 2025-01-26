#include <iostream>


using namespace std;

void choosePivot(int *arr, int size) {
    if (arr[0] > arr[size/2]) {
        swap(arr[0], arr[size/2]);
    }

    if (arr[0] > arr[size-1]) {
        swap(arr[0], arr[size-1]);
    }

    if (arr[size/2] > arr[size-1]) {
        swap(arr[size/2], arr[size-1]);
    }

    swap(arr[size-1], arr[size/2]);
}

int helper (int *arr, int size, int pivotIdx) {
    int itemFromLeftIdx = -1, itemFromRightIdx = -1;
    for(int i=0; i<size-1; i++) {
        if (arr[i] > arr[pivotIdx]) {
            itemFromLeftIdx = i;
            break;
        }
    }
    for(int i=size-1; i>=0; i--) {
        if (arr[i] < arr[pivotIdx]) {
            itemFromRightIdx = i;
            break;
        }
    }

    if (itemFromRightIdx <= itemFromLeftIdx) {
        swap(arr[itemFromLeftIdx], arr[pivotIdx]);
        return itemFromLeftIdx;
    }
    else {
        swap(arr[itemFromRightIdx], arr[itemFromLeftIdx]);
        helper(arr, size, pivotIdx);
    }
}

void quicksort (int *arr, int size) {
    if (size == 1) return;

    if (size == 2) {
        if (arr[0] > arr[1]) {
            swap(arr[0], arr[1]);
        }
        return;
    }

    choosePivot(arr, size);
    int pivotIdx = size-1;

    int idx = helper(arr, size, pivotIdx);

    int *leftarr = new int[idx], *rightarr = new int[size - idx - 1];

    for (int i=0; i<size; i++) {
        if (i < idx) {
            leftarr[i] = arr[i];
        }
        else {
            rightarr[i-idx-1] = arr[i];
        }
    }

    quicksort(leftarr, idx);
    quicksort(rightarr, size-idx-1);
}

int main () {
    int arr[] = {1, 2, 4, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, size);

    for (int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}