#include <iostream>
#include <vector>

void heapifyMax(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void heapSortIncreasing(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}

void heapifyMin(std::vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void heapSortDecreasing(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}

void printArray(const std::vector<int>& arr) {
    for (int x : arr)
        std::cout << x << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr1 = {12, 11, 13, 5, 6, 7};
    std::vector<int> arr2 = arr1;

    std::cout << "Original array: ";
    printArray(arr1);

    heapSortIncreasing(arr1);
    std::cout << "Sorted in increasing order: ";
    printArray(arr1);

    heapSortDecreasing(arr2);
    std::cout << "Sorted in decreasing order: ";
    printArray(arr2);

    return 0;
}