sets = [];

function powerset(S, k, subset) {
  if (k == S.length) {
    sets.push(subset);
    return;
  }
  powerset(S, k + 1, subset);
  powerset(S, k + 1, subset + S[k])
}

powerset('abc', 0, '');
console.log(sets);
