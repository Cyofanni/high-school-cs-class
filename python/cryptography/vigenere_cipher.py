#!usr/bin/python3
#Usage example: python3 vigenere_cipher.py helloworld banana

import sys

def shift_character(plain_c, shift):
    return chr(((ord(plain_c) + shift - 32) % 94) + 32)
 
plain_text = sys.argv[1]
key = sys.argv[2]
key_index = 0

for i in range(len(plain_text)):
    if key_index == len(key):
        key_index = 0
    print(shift_character(plain_text[i], ord(key[key_index]) - 32), end = '')
    key_index = key_index + 1

print()
