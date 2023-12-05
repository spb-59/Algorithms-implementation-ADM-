def heapify(arr: list, heapSize: int, index: int):
    largest = index
    left = index * 2 + 1
    right = index * 2 + 2

    if left < heapSize and arr[left] > arr[largest]:
        largest = left
    if right < heapSize and arr[right] > arr[largest]:
        largest = right

    if largest != index:
        arr[index], arr[largest] = arr[largest], arr[index]
        heapify(arr, heapSize, largest)

def makeHeap(arr: list, lenArr: int):
    for i in range(lenArr // 2 - 1, -1, -1):
        heapify(arr, lenArr, i)

def heapSort(arr: list):
    lenArr = len(arr)

    makeHeap(arr, lenArr)

    for i in range(lenArr - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)

arr = [1, 24, 2, 4, 1, 2]
heapSort(arr)
print(arr)
