function insertion_sort(arr) {
    size_arr = arr.length;
    for (i = 1; i < size_arr; i++) {
        item = arr[i];
        j = i - 1;
        while (j >= 0 && item < a[j]) {
            a[j + 1] = a[j];
            j--
        }
        a[j + 1] = item;
    }
}

//call insertion sort
a = [8, 7, 6, 1, 67, 45, 16, 78, 100, 12, 13, 1065, 23, 1, 78, 39];
insertion_sort(a);
console.log(a);
