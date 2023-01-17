#!/usr/bin/python3

#Usage example: python3 caesar_cipher.py "hello world" 3

import sys

alphabet_size = 26
ascii_base = 97

def shift_character(plain_c, key):
    return chr(((ord(plain_c) + key - ascii_base) % alphabet_size) + ascii_base)

if (len(sys.argv) < 3):
    exit("missing plaintext/key")
    
plain_text = sys.argv[1]
key = sys.argv[2]

for pc in plain_text:
    print(shift_character(pc, int(key)), end = '')

print()
