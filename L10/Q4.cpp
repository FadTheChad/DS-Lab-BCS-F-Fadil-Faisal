#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HeapConverter {
private:
    vector<string> heap;

    int getLeftChild(int index) {
        return 2 * index + 1;
    }

    int getRightChild(int index) {
        return 2 * index + 2;
    }

    void maxHeapify(int size, int index) {
        int largest = index;
        int leftChild = getLeftChild(index);
        int rightChild = getRightChild(index);

        if (leftChild < size && heap[leftChild] > heap[largest])
            largest = leftChild;

        if (rightChild < size && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            maxHeapify(size, largest);
        }
    }

    void buildMaxHeap(int size) {
        for (int i = (size / 2) - 1; i >= 0; i--) {
            maxHeapify(size, i);
        }
    }

public:
    void inputElements() {
        int n;
        cout << "Enter n: ";
        cin >> n;
        cin.ignore();

        heap.resize(n);
        
        for (int i = 0; i < n; i++) {
            getline(cin, heap[i]);
        }
    }

    void convertToMaxHeap() {
        buildMaxHeap(heap.size());
    }

    void displayHeap() {
        cout << "Converted Max Heap: ";
        for (const string& element : heap) {
            cout << element << " ";
        }
        cout << endl;
    }
};

int main() {
    HeapConverter converter;
    
    converter.inputElements();
    converter.convertToMaxHeap();
    converter.displayHeap();

    return 0;
}
