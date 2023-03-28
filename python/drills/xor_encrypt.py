def xor_encrypt_decrypt(pt, k):
    ciphertext = b''
    k_index = 0
    for c in pt:
        if k_index == len(k):
            k_index = 0
        ciphertext += chr(c ^ k[k_index]).encode('ascii')
        k_index += 1

    return ciphertext

plaintext = 'this?Is4SeCret!!!?'
print('plaintext:', plaintext)
plaintext_bytes = plaintext.encode('ascii')
print('plaintext bytes:', plaintext_bytes)
key_bytes = 'p4As!wO0rD3'.encode('ascii')
print('key bytes:', key_bytes)
ciphertext = xor_encrypt_decrypt(plaintext_bytes, key_bytes)
print('ciphertext:', ciphertext)

plaintext_decr = xor_encrypt_decrypt(ciphertext, key_bytes)
print('ciphertext, decrypted:', plaintext_decr)
