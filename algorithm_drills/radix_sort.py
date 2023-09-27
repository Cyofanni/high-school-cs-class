def insertion_sort(ls, key_index):
  for i in range(1, len(ls)):
    item = ls[i]
    j = i - 1
    while j >= 0 and item[key_index] < ls[j][key_index]:
      ls[j + 1] = ls[j]
      j -= 1
    ls[j + 1] = item

nums = [(7, 6, 5), (0, 1, 8), (1, 1, 2), (1, 1, 2), (9, 4, 1), (9, 4, 9),
        (9, 3, 4), (1, 1, 0), (8, 5, 1), (2, 3, 4)]

for i in range(2, -1, -1):
  insertion_sort(nums, i)

print(nums)
