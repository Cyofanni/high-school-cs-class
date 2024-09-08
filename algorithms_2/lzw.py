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

table = [chr(code) for code in range(97, 123)]
table_cp = table.copy()
text = 'abcabcabcabcabcabcabcabc'
enc = lempel_ziv_welch_enc(text, table)
print(enc)
print()
for item in table:
    print(item)
