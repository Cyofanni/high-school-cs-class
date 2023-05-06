import random

def counting_sort(A, k):
    B = [0 for i in range(k)]
    for i in range(len(A)):
        B[A[i]] = B[A[i]] + 1

    for i in range(1, len(B)):
        B[i] = B[i] + B[i - 1]

    C = [0 for i in range(len(A))]

    for i in range(len(A)):
        sorted_index = B[A[i]] - 1
        C[sorted_index] = A[i]
        B[A[i]] = B[A[i]] - 1

    return C
