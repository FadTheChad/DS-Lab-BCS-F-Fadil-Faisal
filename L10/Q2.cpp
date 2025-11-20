#include <iostream>
#include <vector>
using namespace std;

class HeapOperations {
private:
    vector<int> heap;

    int getParent(int idx) {
        return (idx - 1) / 2;
    }

    int getLeftChild(int idx) {
        return 2 * idx + 1;
    }

    int getRightChild(int idx) {
        return 2 * idx + 2;
    }

    void heapify(int size, int index) {
        int largest = index;
        int left = getLeftChild(index);
        int right = getRightChild(index);

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify(size, largest);
        }
    }

public:
    HeapOperations(vector<int> arr) {
        heap = arr;
    }

    bool isMaxHeap() {
        int size = heap.size();
        for (int i = 0; i <= (size / 2) - 1; i++) {
            int left = getLeftChild(i);
            int right = getRightChild(i);

            if (left < size && heap[i] < heap[left])
                return false;

            if (right < size && heap[i] < heap[right])
                return false;
        }
        return true;
    }

    void buildMaxHeap() {
        int size = heap.size();
        for (int i = (size / 2) - 1; i >= 0; i--)
            heapify(size, i);
    }

    void heapSort() {
        int size = heap.size();
        buildMaxHeap();

        for (int i = size - 1; i > 0; i--) {
            swap(heap[0], heap[i]);
            heapify(i, 0);
        }
    }

    void display() {
        for (int i = 0; i < heap.size(); i++)
            cout << heap[i] << " ";
        cout << endl;
    }

    vector<int> getHeap() {
        return heap;
    }
};

int main() {
    vector<int> arr = {40, 25, 35, 10, 20, 30, 15};
    
    HeapOperations heapOps(arr);

    cout << "Max Heap: " << (heapOps.isMaxHeap() ? "Yes" : "No") << endl;

    cout << "\nOriginal Array: ";
    heapOps.display();

    heapOps.heapSort();

    cout << "\nAfter Heap Sort: ";
    heapOps.display();

    return 0;
}
