#include <iostream>

using namespace std;

// Merge two sorted arrays
int* merge(int array1[], int array2[], int size1, int size2) {
    int* array3 = new int[size1 + size2];

    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (array1[i] < array2[j]) {
            array3[k++] = array1[i++];
        } else {
            array3[k++] = array2[j++];
        }
    }

    while (i < size1) {
        array3[k++] = array1[i++];
    }
    while (j < size2) {
        array3[k++] = array2[j++];
    }

    return array3;
}

int* mergeSort(int array[], int size) {
    if (size == 1) {
        int* singleElement = new int[1];
        singleElement[0] = array[0];
        return singleElement;
    }

    int nrElementsLeft = (size + 1) / 2;
    int nrElementsRight = size / 2;

    int* leftarr = new int[nrElementsLeft];
    int* rightarr = new int[nrElementsRight];

    for (int i = 0; i < nrElementsLeft; i++) {
        leftarr[i] = array[i];
    }
    for (int i = 0; i < nrElementsRight; i++) {
        rightarr[i] = array[nrElementsLeft + i];
    }

    int* newLeftArr = mergeSort(leftarr, nrElementsLeft);
    int* newRightArr = mergeSort(rightarr, nrElementsRight);

    int* sortedArray = merge(newLeftArr, newRightArr, nrElementsLeft, nrElementsRight);

    delete[] leftarr;
    delete[] rightarr;
    delete[] newLeftArr;
    delete[] newRightArr;

    return sortedArray;
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int* resArr = mergeSort(arr, size);

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << resArr[i] << " ";
    }
    cout << endl;

    delete[] resArr;

    return 0;
}
