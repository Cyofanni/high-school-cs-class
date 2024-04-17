def dewdney(depth, item):
  if depth == 0:
    print(item, end = '')
    return
  if item == '!':
    dewdney(depth - 1, '|')
    print('(', end = '')
    dewdney(depth - 1, '!')
    print(')', end = '')
    dewdney(depth - 1, '|')
    print('(', end = '')
    dewdney(depth - 1, '!')
    print(')', end = '')
    dewdney(depth - 1, '!')
  if item == '|':
    dewdney(depth - 1, '|')
    dewdney(depth - 1, '|')

dewdney(3, '!')
print()
