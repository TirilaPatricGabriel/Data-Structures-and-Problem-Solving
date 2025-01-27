#include <iostream>

using namespace std;

int choosePivot(int arr[], int start, int end) {
    int mid = (start + end) / 2;

    if (arr[start] > arr[mid]) swap(arr[start], arr[mid]);
    if (arr[start] > arr[end]) swap(arr[start], arr[end]);
    if (arr[mid] > arr[end]) swap(arr[mid], arr[end]);

    swap(arr[mid], arr[end]);
    return arr[end];
}

int partition(int arr[], int start, int end) {
    int pivot = choosePivot(arr, start, end);
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quicksort(int arr[], int start, int end) {
    if (start >= end) return;

    int pivotIdx = partition(arr, start, end);

    quicksort(arr, start, pivotIdx - 1);
    quicksort(arr, pivotIdx + 1, end);
}

int main() {
    int arr[] = {8, 3, 7, 1, 9, 6, 4, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
