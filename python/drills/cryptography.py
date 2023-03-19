import functools, sys

#rotate
ascii_base = 97
alphabet_size = 26

def shift_char(k, char):
    return chr(((ord(char) - ascii_base + k) % alphabet_size) + ascii_base)

plaintext = sys.argv[1]

for key in range(0, 79):
    ciphertext = "".join(list(map(functools.partial(shift_char, key), plaintext)))
    print(ciphertext)

