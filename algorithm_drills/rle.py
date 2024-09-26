data = '_QQQCZZ_'
print(data)

runs = []

count = 0
for i in range(1, len(data)):
    if data[i] != data[i - 1]:
        if (data[i - 1] != '_'):
            runs.append((data[i - 1], count))
        count = 0
    count += 1

print(runs)

compressed_data = ''
for item in runs:
    compressed_data += str(item[1])
    compressed_data += item[0]

print(compressed_data)
