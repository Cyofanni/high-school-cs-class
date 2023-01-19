import sys

def sum_mod(a, b, m):
    return (a + b) % m

def product_mod(a, b, m):
    return (a * b) % m

def exp_mod(base, exp, m):
    return (base ** exp) % m

def print_table(c, m):
    if (c == 's'):
        print("TABLE OF MODULAR SUM")
    elif (c == 'p'):
        print("TABLE OF MODULAR PRODUCT")
    elif (c == 'e'):
        print("TABLE OF MODULAR EXPONENTIATION")
    
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
            elif c == 'e':
                res = exp_mod(i, j, m)
            print(res, ' ', end = '')
            j += 1
        print()
        i += 1
    

if len(sys.argv) < 3:
    print("usage: 'python3 modular_arithmetic.py s 7' prints table of sum modulo 7")
    print("usage: 'python3 modular_arithmetic.py p 7' prints table of product modulo 7")
    print("usage: 'python3 modular_arithmetic.py e 7' prints table of exponentiation modulo 7")    
    exit("missing operation and modulo number")
elif sys.argv[1] != 's' and sys.argv[1] != 'p' and sys.argv[1] != 'e':
    exit("operation character must be 's' (sum), 'p' (product) or 'e' (exponentiation)")

print_table(sys.argv[1], int(sys.argv[2]))
