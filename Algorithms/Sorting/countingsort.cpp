#include <iostream>

using namespace std;

void countingSort (int numbers[], int size) {
    int max = INT_MIN;
    for(int i=0; i<size; i++) {
        if (max < numbers[i]) {
            max = numbers[i];
        }
    }

    int carray[max+1];

    for(int i=0; i<=max; i++) {
        carray[i] = 0;
    }

    for(int i=0; i<size; i++) {
        carray[numbers[i]]++;
    }

    for(int i=1; i<=max; i++) {
        carray[i] += carray[i-1];
    }

    for(int i=max; i>0; i--) {
        carray[i] = carray[i-1];
    }

    int resArray[size];
    for (int i=0; i<size; i++) {
        int pos = carray[numbers[i]];
        resArray[pos] = numbers[i];
        carray[numbers[i]]++;
    }

    for(int i=0; i<size; i++) {
        cout<<resArray[i]<<" ";
    }
}

int main () {
    int numbers[15] = {3, 6, 4, 3, 2, 6, 8, 4, 3, 2, 5, 7, 8, 2, 7};

    int size = sizeof(numbers) / sizeof(numbers[0]);

    countingSort(numbers, size);
}