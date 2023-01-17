#!usr/bin/python3
#Usage example: python3 vigenere_cipher.py helloworld banana

import sys

alphabet_size = 26
ascii_base = 97

def shift_character(plain_c, shift):
    return chr(((ord(plain_c) + shift - ascii_base) % alphabet_size) + ascii_base)

if (len(sys.argv) < 3):
    exit("missing plaintext/key")

plain_text = sys.argv[1]
key = sys.argv[2]
key_index = 0

for pc in plain_text:
    if key_index == len(key):
        key_index = 0
    print(shift_character(pc, ord(key[key_index]) - ascii_base), end = '')
    key_index = key_index + 1

print()
