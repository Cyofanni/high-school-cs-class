def partition(A, low, high):
    i = low - 1
    pivot = A[high]
    for j in range(low, high + 1):
        if A[j] <= pivot:
            i = i + 1
            temp = A[i]
            A[i] = A[j]
            A[j] = temp
    return i

def quick_sort(A, low, high):
    if low >= high:
        return
    pivot_index = partition(A, low, high)
    quick_sort(A, low, pivot_index - 1)
    quick_sort(A, pivot_index + 1, high)
