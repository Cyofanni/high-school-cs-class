function merge(v, l, m, h) {
  let left = v.slice(l, m + 1);
  let right = v.slice(m + 1, h + 1);
  left.push(Infinity);
  right.push(Infinity);

  let li = 0;
  let ri = 0;

  for (let i = l; i <= h; i++) {
    if (left[li] <= right[ri]) {
      v[i] = left[li];
      li++;
    }
    else {
      v[i] = right[ri];
      ri++;
    }
  }
}

function merge_sort(v, l, h) {
  if (l < h) {
    let m = Math.floor((l + h) / 2);
    merge_sort(v, l, m);
    merge_sort(v, m + 1, h);
    merge(v, l, m, h)
  }
}

ar = [100, 1, 2, 6, 5, 4, 6, 1, 15, 4, 3, 3, 35, 10, 2, -3];
size = ar.length;
console.log(ar);
merge_sort(ar, 0, size - 1);
console.log(ar);
