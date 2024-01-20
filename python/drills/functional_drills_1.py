#map
mozart_works = ('le nozze di figaro', 'così fan tutte', 'don giovanni'
                'requiem', 'clarinet concerto K 622')

mp = map(len, mozart_works)
title_lengths = list(mp) #consumed
mp1 = map(len, mozart_works)
for i in mp1:
    print(i)

print()

#filter
def parity(num):
    return num % 2 == 0

numbers = [5, 6, 4, 1, 8, 76, 2, 4, 5]
even_filter = filter(parity, numbers)
for p in even_filter:
    print(p)
even_filter = filter(parity, numbers)
evens = tuple(even_filter)
print(evens)
