table = {'a': 45, 'b': 13,
         'c': 12, 'd': 16,
         'e': 9, 'f': 5}

table_copy = {'a': 45, 'b': 13,
              'c': 12, 'd': 16,
              'e': 9, 'f': 5}

tree = {'a': [None, None], 'b': [None, None],
        'c': [None, None], 'd': [None, None],
        'e': [None, None], 'f': [None, None]}

def extract_min(d):
  min_v = min(d, key = d.get)
  item = (min_v, d[min_v])
  d.pop(min_v)
  return item

n = len(table)
i = 0

for j in range(1, n):
    x = extract_min(table)
    y = extract_min(table)
    sum_freqs = x[1] + y[1]
    node_label = 'n' + str(i)
    table[node_label] = sum_freqs
    table_copy[node_label] = sum_freqs
    tree[node_label] = [x[0], y[0]]
    i += 1

print('frequencies:')
print(table_copy)
print('tree:')
for it in tree.items():
    print(it)
