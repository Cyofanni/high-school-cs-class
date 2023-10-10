data = '_AAAAAAAAAAAAAAAABCDEEE_'
runs = []

count = 0
for i in range(len(data)):
    if i > 0 and data[i] != data[i - 1]:
        if (data[i - 1] != '_'):
            runs.append((data[i - 1], count))
        count = 0
    count += 1

compressed_data = ''
for item in runs:
    compressed_data += str(item[1])
    compressed_data += item[0]

print(compressed_data)
