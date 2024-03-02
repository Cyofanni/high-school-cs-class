function exchange(x, y) {
    return [y, x];
}

function partition(v, l, h) {
    let pivot = v[l];
    let i = l;

    for (let j = l + 1; j <= h; j++) {
	if (v[j] <= pivot) {
	    i++;
	    let exch = exchange(v[i], v[j]);
	    v[i] = exch[0];
	    v[j] = exch[1];
	}
    }

    v[l] = v[i];
    v[i] = pivot;

    return i;
}

function quicksort(v, l, h) {
    if (l < h) {
	q = partition(v, l, h);
	quicksort(v, l, q - 1);
	quicksort(v, q + 1, h);
    }
}

ar = [1, 2, 3, 4, 5, 10, 120, 3, 3, 2, -1, 300, 1, 2, 3, 8, 6, 35];
console.log(ar);
quicksort(ar, 0, ar.length - 1);
console.log(ar);
