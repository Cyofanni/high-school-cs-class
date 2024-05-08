#https://leetcode.com/problems/palindrome-number/description/

def num_digits(n):
    if n == 0:
        return 1
    c = 0
    while n != 0:
        n = n // 10
        c += 1
    return c

def is_palindrome(n):
    if n < 0:
      return False

    m = n
    num_d = num_digits(n)
    e = num_d - 1
    l = 0
    r = num_d - 1

    while l <= r:
        l_d = n % 10
        r_d = m // 10 ** e
        if l_d != r_d:
            return False
        n = n // 10
        m = m % 10 ** e
        l = l + 1
        r = r - 1
        e -= 1

    return True

while True:
    print('enter an integer:')
    n = int(input())
    print('palindrome:', is_palindrome(n))
    print()
