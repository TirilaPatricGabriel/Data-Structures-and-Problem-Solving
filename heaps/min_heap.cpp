#include <iostream>
using namespace std;

class MinHeap {
private:
    int array[50];
    int size;

public:
    MinHeap() : size(0) {}

    void sift_up(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (array[parent] > array[idx]) {
                swap(array[parent], array[idx]);
                idx = parent;
            } else {
                break;
            }
        }
    }

    void sift_down(int idx) {
        while (true) {
            int leftIdx = 2 * idx + 1;
            int rightIdx = 2 * idx + 2;
            int smallIdx = idx;

            if (leftIdx < size && array[leftIdx] < array[smallIdx]) {
                smallIdx = leftIdx;
            }
            if (rightIdx < size && array[rightIdx] < array[smallIdx]) {
                smallIdx = rightIdx;
            }

            if (smallIdx != idx) {
                swap(array[idx], array[smallIdx]);
                idx = smallIdx;
            } else {
                break;
            }
        }
    }

    int getMin() const {
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return -1;
        }
        return array[0];
    }

    void insert(int value) {
        if (size >= 50) {
            cout << "Heap is full" << endl;
            return;
        }
        array[size] = value;
        sift_up(size);
        size++;
    }

    int extract_min() {
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return -1;
        }

        int minVal = array[0];
        array[0] = array[size - 1];
        size--;
        sift_down(0);

        return minVal;
    }

    void updateByIdx(int idx, int value) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid index" << endl;
            return;
        }

        int oldVal = array[idx];
        array[idx] = value;
        if (value < oldVal) {
            sift_up(idx);
        } else {
            sift_down(idx);
        }
    }

    void printHeap() const {
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void heapify(int newArray[], int size) {
        for (int i = 0; i < size; i++) {
            this->array[i] = newArray[i];
        }
        this->size = size;
        for (int i = (size / 2) - 1; i >= 0; i--) {
            this->sift_down(i);
        }
    }
};

int main () {
    MinHeap mh;
    mh.insert(4);
    mh.insert(5);
    mh.insert(2);
    mh.insert(7);
    mh.insert(1);
    mh.insert(8);
    mh.printHeap();

    cout<<mh.extract_min()<<" "<<mh.extract_min()<<" "<<mh.extract_min()<<endl;

    int s[6] = {2, 6, 3, 5, 7, 8};
    mh.heapify(s, 6);
    mh.printHeap();
    cout<<mh.extract_min()<<" "<<mh.extract_min()<<" "<<mh.extract_min()<<endl;

}
