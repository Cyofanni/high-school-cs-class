import math

#return x^0/0! + x^1/1! ... x^n/n! (around x = 0)
def maclaurin_exp_build(deg):
    s = ''
    for i in range(0, int(deg) + 1):
        s += 'x^' + str(i) + '/' + str(i) + '!'
        if i != int(deg):
            s += ' + '

    return s

def maclaurin_exp_eval(deg, x):
    num = 1
    den = 1
    s = 1
    for i in range(1, deg + 1):
        num = num * x
        den = den * i
        s = s + num / den

    return s

#approximate e^0.2
for i in range(15):
    print(maclaurin_exp_build(str(i)))
    print(maclaurin_exp_eval(i, 0.5))
    print('\n')

print(math.exp(0.5))
