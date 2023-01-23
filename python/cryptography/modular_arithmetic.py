import sys

def sum_mod(a, b, m):
    return (a + b) % m

def product_mod(a, b, m):
    return (a * b) % m

def naive_exp_mod(base, exp, m):
    return (base ** exp) % m

#Fermat's little theorem:
# if m is prime and a is not a multiple of m => (a^(m-1)) mod m = 1
def little_fermat_verify(base, m):
    return naive_exp_mod(base, m - 1, m) == 1

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
                res = naive_exp_mod(i, j, m)
            print(res, ' ', end = '')
            j += 1
        print()
        i += 1

if len(sys.argv) < 3:
    print("usage: 'python3 modular_arithmetic.py s 7' prints table of sum modulo 7")
    print("usage: 'python3 modular_arithmetic.py p 7' prints table of product modulo 7")
    print("usage: 'python3 modular_arithmetic.py e 7' prints table of exponentiation modulo 7")
    print("usage: 'python3 modular_arithmetic.py f 7' very Fermat's little theorem on m = 7")
    exit("missing operation and modulo number")
elif sys.argv[1] != 's' and sys.argv[1] != 'p' and sys.argv[1] != 'e' and sys.argv[1] != 'f':
    exit("operation character must be 's' (sum), 'p' (product), 'e' (exponentiation), " 
            "'f' to verify Fermat's little theorem")

if sys.argv[1] == 'f':
    f = little_fermat_verify(int(sys.argv[2]), int(sys.argv[3]))
    if f == True:
        print("your numbers agree with Fermat's theorem")
    else:
        print("your numbers do not agree with Fermat's theorem")
else:
    print_table(sys.argv[1], int(sys.argv[2]))
