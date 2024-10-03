def compress(data):
  sz = len(data)
  runs = []
  count = 0
  result = ''

  for i in range(sz):
    if i >= 1 and data[i] != data[i - 1]:
        runs.append((data[i - 1], count))
        count = 0
    count += 1

  if sz > 0:
    runs.append((data[sz - 1], count))

  for item in runs:
    result += item[0] + str(item[1])

  return result, runs

def decompress(runs):
  data = ''

  for run in runs:
    data += run[0] * run[1]

  return data

data = input()
data_comp = compress(data)
print(data_comp)
print(decompress(data_comp[1]))
