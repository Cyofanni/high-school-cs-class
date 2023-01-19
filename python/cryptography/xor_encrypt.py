#usage: python3 plaintext decimal_key
import sys

def xor_enc_dec(pt, k):
    res = b''
    k_length = len(k)
    k_index = 0
    for pc in pt:
        res += ((ord(pc) ^ int(k[k_index]))).to_bytes(1, byteorder = 'big')
        k_index += 1
        if k_index == k_length:
            k_index = 0
    return res

plaintext = sys.argv[1]
key = int(sys.argv[2])
key_bytes = key.to_bytes(4, byteorder = 'big')

res = xor_enc_dec(plaintext, key_bytes)
for b in res:
    print("{:02x}".format(b), end = '')
print()
