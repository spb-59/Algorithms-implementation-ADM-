#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int heapSize, int index) {
  int largest = index;
  int leftChild = 2 * index + 1;
  int rightChild = 2 * index + 2;

  if (leftChild < heapSize && arr[leftChild] > arr[largest]) {
    largest = leftChild;
  }
  if (rightChild < heapSize && arr[rightChild] > arr[largest]) {
    largest = rightChild;
  }

  if (largest != index) {
    swap(arr[index], arr[largest]);
    heapify(arr, heapSize, index);
  }
}

void heapifyMin(vector<int>& arr, int heapSize, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

  
    if (leftChild < heapSize && arr[leftChild] < arr[smallest]) {
        smallest = leftChild;
    }
    if (rightChild < heapSize && arr[rightChild] < arr[smallest]) {
        smallest = rightChild;
    }

  
    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        heapifyMin(arr, heapSize, smallest);
    }
}


void buildHeap(vector<int>& arr, int len) {
  for (int i = len / 2 - 1; i >= 0; --i) {
    heapify(arr, len, i);
  }
}

void buildHeapMin(vector<int>& arr, int len) {
  for (int i = len / 2 - 1; i >= 0; --i) {
    heapifyMin(arr, len, i);
  }
}



void heapSort(vector<int>& arr) {
  int len = arr.size();

  buildHeap(arr, len);

  for (int i = len - 1; i > 0; --i) {
    swap(arr[0], arr[i]);

    heapify(arr, i, 0);
  }
}

void heapSortRev(vector<int>& arr) {
  int len = arr.size();

  buildHeapMin(arr, len);

  for (int i = len - 1; i > 0; --i) {
    swap(arr[0], arr[i]);

    heapifyMin(arr, i, 0);
  }
}



int main() {
  vector<int> arr = {4, 10, 3, 5, 1};

  heapSortRev(arr);

  cout << "Sorted array: ";
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}