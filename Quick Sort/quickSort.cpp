#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int index = low - 1;
    int p = low + rand() % (high - low + 1);
    int pivot = arr[p];
    swap(arr[high], arr[p]);

    for (int i = low; i <= high; i++) {
        if (arr[i] <= pivot) {
            swap(arr[++index], arr[i]);
        }
    }

    return index;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 15, 9, 2, 6, 5, 3, 5,20};
    int size = arr.size();

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (const auto& element : arr) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
