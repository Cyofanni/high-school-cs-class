codes = []

def generate_gray_codes(k):
  if k == 1:
    codes.append([0])
    codes.append([1])
    return

  generate_gray_codes(k - 1)
  old_codes = codes.copy()
  size_codes = len(codes)
  for i in range(size_codes):
    codes[i] = [0] + codes[i]
  for i in range(size_codes):
    codes.append([1] + old_codes[i])
  size_codes = len(codes)
  middle = size_codes // 2
  #comment the line below to get positional binary encoding
  codes[middle : size_codes] = codes[size_codes - 1 : middle - 1 : -1]

generate_gray_codes(5)
for code in codes:
  print(code)
