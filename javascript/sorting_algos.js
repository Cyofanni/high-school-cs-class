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

function selection_sort(array) {
    for (i = 0; i <= array.length - 1; i++) {
	min = array[i];
	pos_min = i;
	for (j = i + 1; j < array.length; j++) {
	    if (array[j] < min) {
		min = array[j];
		pos_min = j;
	    }
	}
	t = array[i];
	array[i] = array[pos_min];
	array[pos_min] = t;
    }
}

//call insertion sort
a = [8, 7, 6, 1, 67, 45, 16, 78, 100, 12, 13, 1065, 23, 1, 78, 39];
insertion_sort(a);
console.log(a);

//call selection sort
b = [2, 4, 6, 8, 10, 14, 1, 3, 5, 7, 90, 34, 12, 61];
selection_sort(b);
console.log(b);

//call selection sort on an array of strings
composers = ['bach', 'mozart', 'brahms', 'vivaldi', 'beethoven', 'chopin']
selection_sort(composers);
console.log(composers);

//use map to apply selection sort on each item of a list of lists of numbers
ll = [[6, 5, 4, 3, 1], [56, 1, 87, 6, 45], [43, 2, 76, 56], [0, 1, 34, -1, 3]];
ll.map(selection_sort);
console.log(ll);
