#!usr/bin/python3
#Usage example: python3 invert_vigenere_key.py banana

import sys

alphabet_size = 26
ascii_base = 97

def invert_character(c):
    if (ord(c) == ascii_base):
        return c
    return chr(alphabet_size - (ord(c) - ascii_base) + ascii_base)

if (len(sys.argv) < 3):
    exit("missing plaintext/key")

key = sys.argv[1]

for c in key:
    print(invert_character(c), end = '')

print()
