plaintext = 'galliaestomnisdivisainpartestres'

key = 3
ciphertext_list = list(map(lambda c: chr((ord(c) + key - 97) % 26 + 97), plaintext))
ciphertext = ''.join(ciphertext_list)
print(plaintext)
print(ciphertext)
decryptedtext_list = list(map(lambda c: chr((ord(c) - key - 97) % 26 + 97), ciphertext))
decryptedtext = ''.join(decryptedtext_list)
print(decryptedtext)
