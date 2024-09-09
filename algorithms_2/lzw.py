def lempel_ziv_welch_enc(text, table):
    curr = text[0]
    codes = []
    for i in range(1, len(text)):
        sym = text[i]
        if curr + sym in table:
            curr += sym
        else:
            table.append(curr + sym)
            ind = table.index(curr)
            codes.append(ind)
            curr = sym

    ind = table.index(curr)
    codes.append(ind)
    return codes

def lempel_ziv_welch_dec(codes, table):
    read = codes[0]
    decoded = table[read]
    S = decoded
    decoded_string = decoded

    for i in range(1, len(codes)):
        read = codes[i]
        prev_decoded = decoded
        if read < len(table):
            decoded = table[read]
            S = prev_decoded + decoded[0]
            table.append(S)
        else:
            decoded = prev_decoded + prev_decoded[0]
            table.append(decoded)
        decoded_string += decoded

    return decoded_string

table = [chr(code) for code in range(97, 123)]
table_cp = table.copy()
text = 'appleqowieuqwappleoiappleapp'
print('size of uncompressed data:', len(text))
print()
enc = lempel_ziv_welch_enc(text, table)
dec = lempel_ziv_welch_dec(enc, table_cp)
print(enc)
print('\nsize of compressed data:', len(enc))
print('\ncheck decompressed == initial data')
print(dec)
print(dec == text)
