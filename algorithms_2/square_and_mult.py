def sq_n_mult(b, exp):
    r = 1
    for bit in exp:
        if bit == 0:
            r = r * r    #square
        elif bit == 1:
            r = r * r    #square
            r = r * b    #multiply

    return r

#3 ^ 19
print(sq_n_mult(3, [1,0,0,1,1]))
