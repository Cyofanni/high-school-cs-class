#public parameters
g, n = 5, 23

#Alice's secret
a = 4
#Bob's secret
b = 3

#Alice's computation: g^a mod n
A = pow(g, a, n)

#Bob's computation: g^b mod n
B = pow(g, b, n)

#Alice receives B from Bob, and computes B^a mod n
shared_A = pow(B, a, n)

#Bob receives A from Alice, and computes A^b mod n
shared_B = pow(A, b, n)

#shared_A == shared_B, Alice and Bob have a shared secret
print(shared_A == shared_B)
