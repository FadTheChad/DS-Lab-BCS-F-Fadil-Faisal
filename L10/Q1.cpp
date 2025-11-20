#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    int getParent(int index) {
        return (index - 1) / 2;
    }

    int getLeftChild(int index) {
        return 2 * index + 1;
    }

    int getRightChild(int index) {
        return 2 * index + 2;
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = getLeftChild(index);
        int right = getRightChild(index);

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int index) {
        while (index > 0 && heap[getParent(index)] < heap[index]) {
            swap(heap[index], heap[getParent(index)]);
            index = getParent(index);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int getMax() {
        return heap[0];
    }

    int extractMax() {
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxVal;
    }

    void update(int index, int newValue) {
        int oldValue = heap[index];
        heap[index] = newValue;

        if (newValue > oldValue)
            heapifyUp(index);
        else
            heapifyDown(index);
    }

    void remove(int index) {
        update(index, getMax() + 1);
        extractMax();
    }

    void display() {
        for (int i = 0; i < heap.size(); i++)
            cout << heap[i] << " ";
        cout << endl;
    }

    bool empty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }
};

int main() {
    MaxHeap heap;

    heap.insert(15);
    heap.insert(22);
    heap.insert(10);
    heap.insert(5);
    heap.insert(18);

    cout << "Initial Max Heap: ";
    heap.display();

    heap.update(2, 25);
    cout << "After updating index 2: ";
    heap.display();

    heap.remove(0);
    cout << "After removing root: ";
    heap.display();

    cout << "Extracting all elements: ";
    while (!heap.empty()) {
        cout << heap.extractMax() << " ";
    }
    cout << endl;

    return 0;
}
