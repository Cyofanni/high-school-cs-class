#Usage example: python3 caesar_cipher.py "hello world" 3

import sys

def shift_character(plain_c, key):
    return chr(((ord(plain_c) + key - 32) % 95) + 32)


plain_text = sys.argv[1]
key = sys.argv[2]

for i in range(len(plain_text)):
    print(shift_character(plain_text[i], int(key)), end = '')

print()
