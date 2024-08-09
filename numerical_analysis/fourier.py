#compute square wave's coefficients

import numpy as np
from sympy import *

T = 4
omega = (2*np.pi)/T
t = Symbol('t')

A = [0]*10
B = [0]*10
A[0] = (1/T)*(integrate(1,(t,0,T/2))+integrate(-1,(t,T/2,T)))

for k in range(1, 10):
  A[k] = (2/T)*(integrate(1*cos(k*omega*t),(t,0,T/2))+integrate(-1*cos(k*omega*t),\
         (t,T/2,T)))
  B[k] = (2/T)*(integrate(1*sin(k*omega*t),(t,0,T/2))+integrate(-1*sin(k*omega*t),\
         (t,T/2,T)))

print(A)
print(B)
print('known coefficients: ')
for k in range(1, 10, 2):
  print('B_' + str(k) + ': ', end='')
  print((4/np.pi)/k, end='\n')
