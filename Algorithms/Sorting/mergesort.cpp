#include <iostream>

using namespace std;

int* merge(int array1[], int array2[], int size1, int size2) {
    int* array3 = new int[size1+size2];

    int i = 0, j = 0;

    while (i < size1 && j < size2) {
        if (array1[i] < array2[j]) {
            array3[i+j] = array1[i];
            i+=1;
        } else {
            array3[i+j] = array2[j];
            j+=1;
        }
    }

    while (i<size1) {
        array3[i+j] = array1[i];
        i++;
    }
    while(j<size2) {
        array3[i+j] = array2[j];
        j++;
    }

    return array3;
}

int* mergeSort (int array[], int size) {
    if (size == 1) {
        return array;
    }
    int left = 0, right = size-1, middle = (left+right)/2;

    int nrElementsLeft, nrElementsRight = size/2;
    if (size%2) {
        nrElementsLeft = size/2 + 1;
    } else {
        nrElementsLeft = size/2;
    }
    int leftarr[nrElementsLeft], rightarr[size/2];

    for(int i=0; i<size; i++) {
        if (i < nrElementsLeft) {
            leftarr[i] = array[i];
        } else {
            rightarr[i-nrElementsLeft] = array[i];
        }
    }

    int* newLeftArr = mergeSort(leftarr, nrElementsLeft);
    int* newRightArr = mergeSort(rightarr, nrElementsRight);

    return merge(newLeftArr, newRightArr, nrElementsLeft, nrElementsRight);
}

int main () {
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int* resArr = mergeSort(arr, size);

    for (int i=0; i<size; i++) {
        cout<<resArr[i]<<" ";
    }
    delete[] resArr;
}