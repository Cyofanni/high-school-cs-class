import sys

def sum_mod(a, b, m):
    return (a + b) % m

def product_mod(a, b, m):
    return (a * b) % m

def print_table(c, m):
    if (c == 's'):
        print("TABLE OF MODULAR SUM")
    elif (c == 'p'):
        print("TABLE OF MODULAR PRODUCT")

    print()
    i = 0
    print('   ', end = '')
    while i < m:
        print(i, ' ', end = '')
        i += 1

    print()
    print()
    i = 0
    while i < m:
        print(i, ' ', end = '')
        j = 0
        while j < m:
            res = 0
            if c == 's':
                res = sum_mod(i, j, m)
            elif c == 'p':
                res = product_mod(i, j, m)
            print(res, ' ', end = '')
            j += 1
        print()
        i += 1


if len(sys.argv) < 3:
    exit("missing operation and modulo number")

print_table(sys.argv[1], int(sys.argv[2]))

