def extract_min(d):
  min_v = min(d, key = d.get)
  item = (min_v, d[min_v])
  d.pop(min_v)
  return item

def huffman(table):
  tree = dict()
  i = 0
  while len(table) >= 2:
    x = extract_min(table)
    y = extract_min(table)
    sum_freqs = x[1] + y[1]
    node_label = 'n_' + str(sum_freqs) + '_' + str(i)
    table[node_label] = sum_freqs
    tree[node_label] = [x[0], y[0]]
    i += 1

  return tree

table = {'a': 45, 'b': 13,
         'c': 12, 'd': 16,
         'e': 9, 'f': 5}

table_copy = table.copy()

print('frequencies:')
print(table_copy)
tree = huffman(table)
print('tree:')
for it in tree.items():
    print(it)
