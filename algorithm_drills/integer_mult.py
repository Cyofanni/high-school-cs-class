#integer multiplication, divide and conquer
def mr(x, y, n):
    if n <= 1:
        return x * y
    a = x//(10**(n/2))
    b = x%(10**(n/2))
    c = y//(10**(n/2))
    d = y%(10**(n/2))
    return (10**n)*mr(a,c,n//2)+(10**(n//2))*(mr(a,d,n//2)+mr(b,c,n//2))+mr(b,d,n//2)

def karatsuba(x, y, n):
    if n <= 1:
        return x * y
    a = x//(10**(n/2))
    b = x%(10**(n/2))
    c = y//(10**(n/2))
    d = y%(10**(n/2))
    ac = karatsuba(a, c, n//2)
    bd = karatsuba(b, d, n//2)
    k1 = a + b
    k2 = c + d
    k3 = karatsuba(k1, k2, n//2)
    return (10**n)*ac + (10**(n//2))*(k3-ac-bd) + bd

n = 16
x = 2000_7653
y = 4231_5463
r1 = mr(x, y, n)
r2 = karatsuba(x, y, n)
r3 = x * y
print(r1, r2, r3)
print(r1 == r2 == r3)
