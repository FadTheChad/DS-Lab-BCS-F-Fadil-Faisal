#include <iostream>
#include <vector>
using namespace std;

class KthLargestFinder {
private:
    vector<int> heap;

    int getParent(int i) {
        return (i - 1) / 2;
    }

    int getLeft(int i) {
        return 2 * i + 1;
    }

    int getRight(int i) {
        return 2 * i + 2;
    }

    void heapifyDown(int heapSize, int index) {
        int largest = index;
        int leftIdx = getLeft(index);
        int rightIdx = getRight(index);

        if (leftIdx < heapSize && heap[leftIdx] > heap[largest])
            largest = leftIdx;

        if (rightIdx < heapSize && heap[rightIdx] > heap[largest])
            largest = rightIdx;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(heapSize, largest);
        }
    }

    void createMaxHeap(int heapSize) {
        for (int i = (heapSize / 2) - 1; i >= 0; i--) {
            heapifyDown(heapSize, i);
        }
    }

public:
    KthLargestFinder(vector<int> arr) {
        heap = arr;
    }

    int findKthLargest(int k) {
        int heapSize = heap.size();
        createMaxHeap(heapSize);

        for (int i = heapSize - 1; i >= heapSize - k + 1; i--) {
            swap(heap[0], heap[i]);
            heapifyDown(i, 0);
        }

        return heap[0];
    }
};

int main() {
    int n, k;

    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter num " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Enter the k'th value: ";
    cin >> k;

    KthLargestFinder finder(arr);
    cout << "K'th largest element: " << finder.findKthLargest(k) << endl;

    return 0;
}
