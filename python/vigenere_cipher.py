import sys

def shift_character(plain_c, key):
     #print(plain_c, key)
     return chr(((ord(plain_c) + ord(key) - 96  - 32) % 95) + 32)


plain_text = sys.argv[1]
key = sys.argv[2]
key_index = 0

for i in range(len(plain_text)):
    if key_index == len(key):
        key_index = 0
    print(shift_character(plain_text[i], key[key_index]), end = '')
    key_index = key_index + 1

print()
