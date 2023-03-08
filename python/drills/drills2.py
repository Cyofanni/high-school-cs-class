#max, min, sum functions on sequences
max("abtdet") #t
max([5, 4, 10, 1]) #10
sum([5, 4, 10, 1]) #20

max([5,4,10,1], [5, 4, 3, 10], [5, 4, 6, 10, 11, 20], key = sum) #get item with maximum sum

#print sum of each item in a list of lists
lss = [[5,4,10,1, 0, 0, 0, 0, 0, 0], [5, 4, 3, 10], [5, 4, 6, 10, 11, 20]]
for i in lss:
    print(sum(i))

#tuples (immutable objects)
mozart_operas = ('die zauberflote', 'le nozze di figaro', 'don giovanni')
'''>>> mozart_operas[0] = 'abcde'
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: 'tuple' object does not support item assignment
'''

#get maximum-sum list
lss = [[5,4,10,1, 0, 0, 0, 0, 0, 0], [5, 4, 3, 10], [5, 4, 6, 10, 11, 20]]
max(lss, key = sum)

#get maximum-length string, in a tuple of strings
animals = ('bee', 'snake', 'snail', 'wasp', 'rhinoceros', 'dog')
max(animals, key = len)

#apply caesar cipher's shift on a character
def shift(plaintext_character, key):
    return chr(((ord(plaintext_character) - 97 + k) % 26) + 97)

for k in range(0, 52):
    for ascii_code in range(97, 123):
        print(shift(chr(ascii_code), k), end = ' ')
    print()
