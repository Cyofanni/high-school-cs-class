permutations = []

def compute_permutations(word, k, permutation):
  if k == len(word):
    permutation_str = ''.join(permutation)
    if permutation_str not in permutations:
      permutations.append(permutation_str)
    return

  permutation[k] = word[k]
  compute_permutations(word, k + 1, permutation)

  for i in range(1, len(word)):
    t = word[0]
    word[0] = word[i]
    word[i] = t
    t = permutation[0]
    permutation[0] = permutation[i]
    permutation[i] = t
    compute_permutations(word, k + 1, permutation)

st = 'star'
st_l = list(st)
compute_permutations(st_l, 0, ['' for i in range(len(st_l))])
print('#anagrams:', len(permutations))
for p in permutations:
  print(p)
