def lempel_ziv_welch_enc(text, table):
    curr = text[0]
    for i in range(1, len(text)):
        curr += text[i]
        if curr not in table:
            table.append(curr[0:len(curr)])
            curr = curr[len(curr) - 1]

table = [chr(code) for code in range(97, 123)]
text = 'tobeornottobeortobeornot'
lempel_ziv_welch_enc(text, table)
for item in table:
    print(item)
