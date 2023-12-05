# import random

# def partition(arr, low, high):
#     pivot_index = random.randint(low,high-1)
#     pivot = arr[pivot_index]

#     arr[pivot_index], arr[high] = arr[high], arr[pivot_index]

#     index = low - 1
#     for i in range(low, high):
#         if arr[i] < pivot:
#             index += 1
#             arr[i], arr[index] = arr[index], arr[i]

#     arr[index + 1], arr[high] = arr[high], arr[index + 1]
#     return index + 1

# def quickSort(arr, low, high):
#     if high > low:
#         p = partition(arr, low, high)
#         quickSort(arr, low, p - 1)
#         quickSort(arr, p + 1, high)


# arr = [12, 21, 3, 12, 3, 1, 2]
# quickSort(arr, 0, len(arr) - 1)
# print(arr)


import random

def quicksort(arr):
    if len(arr) <= 1:
        return arr
    else:
        # Choose a random pivot
        pivot_index = random.randint(0, len(arr) - 1)
        pivot = arr[pivot_index]

        # Partition the array into elements less than and greater than the pivot
        less = [x for i, x in enumerate(arr) if x <= pivot and i != pivot_index]
        greater = [x for i, x in enumerate(arr) if x > pivot and i != pivot_index]

        # Recursively sort the sub-arrays
        return quicksort(less) + [pivot] + quicksort(greater)

# Example usage:
my_list = [12, 21, 3, 12, 3, 1, 2]
sorted_list = quicksort(my_list)
print(sorted_list)