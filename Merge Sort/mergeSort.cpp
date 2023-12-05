#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int low, int middle, int high) {
  int index;
  vector<int> temp1, temp2;

  for (int i = low; i < middle; i++) {
    temp1.push_back(arr[i]);
  }
  for (int i = middle; i < high; i++) {
    temp2.push_back(arr[i]);
  }

  index = low;

  while (!temp1.empty() && !temp2.empty()) {
    if (temp1.front() <= temp2.front()) {
      arr[index++] = temp1.front();
      temp1.erase(temp1.begin());
    } else {
      arr[index++] = temp2.front();
      temp2.erase(temp2.begin());
    }
  }

  while (!temp1.empty()) {
    arr[index++] = temp1.front();
    temp1.erase(temp1.begin());
  }

  while (!temp2.empty()) {
    arr[index++] = temp2.front();
    temp2.erase(temp2.begin());
  }
}

void mergeSort(vector<int>& arr, int low, int high) {

  int middle;
  if (low < high-1) {
    middle = (low + high) / 2;
    mergeSort(arr, low, middle);
    mergeSort(arr, middle, high);
    merge(arr, low, middle, high);
  }
}

int main(int argc, char const* argv[]) {
  std::vector<int> arr = {38, 27, 43, 3, 1};
  int n = arr.size();

  mergeSort(arr, 0, n);

  std::cout << "Sorted array: ";
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  return 0;
}



