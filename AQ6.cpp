#include <iostream>
#include <vector>

class MaxHeapPriorityQueue {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            std::cout << "Priority queue is empty!" << std::endl;
            return -1;
        }
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return maxVal;
    }

    int getMax() const {
        if (heap.empty()) {
            std::cout << "Priority queue is empty!" << std::endl;
            return -1;
        }
        return heap[0];
    }

    bool isEmpty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }

    void display() const {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

class MinHeapPriorityQueue {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left] < heap[smallest])
                smallest = left;
            if (right < size && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != index) {
                std::swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            std::cout << "Priority queue is empty!" << std::endl;
            return -1;
        }
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return minVal;
    }

    int getMin() const {
        if (heap.empty()) {
            std::cout << "Priority queue is empty!" << std::endl;
            return -1;
        }
        return heap[0];
    }

    bool isEmpty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }

    void display() const {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::cout << "Max-Heap Priority Queue (Higher number = Higher priority)\n";
    MaxHeapPriorityQueue maxPQ;
    maxPQ.insert(10);
    maxPQ.insert(30);
    maxPQ.insert(20);
    maxPQ.insert(5);
    maxPQ.insert(40);

    std::cout << "Max PQ: ";
    maxPQ.display();
    std::cout << "Extract Max: " << maxPQ.extractMax() << std::endl;
    std::cout << "Extract Max: " << maxPQ.extractMax() << std::endl;
    std::cout << "Current Max PQ: ";
    maxPQ.display();

    std::cout << "\nMin-Heap Priority Queue (Lower number = Higher priority)\n";
    MinHeapPriorityQueue minPQ;
    minPQ.insert(10);
    minPQ.insert(30);
    minPQ.insert(20);
    minPQ.insert(5);
    minPQ.insert(40);

    std::cout << "Min PQ: ";
    minPQ.display();
    std::cout << "Extract Min: " << minPQ.extractMin() << std::endl;
    std::cout << "Extract Min: " << minPQ.extractMin() << std::endl;
    std::cout << "Current Min PQ: ";
    minPQ.display();

    return 0;
}