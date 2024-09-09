#compute fourier coefficients by numerical integration
import numpy as np

def f1(t):
  return np.sqrt(np.sin(t)*np.cos(t))

def f2(t):
  return np.exp(np.sin(t))

def f3(t):
  return t

def integral_0(f, t):
  return np.trapz(f(t), t)

def integral_1(f, g, k, omega, t):
  return np.trapz(f(t)*g(k*omega*t), t)

def fourier_series(f, T, n):
  omega = (2*np.pi)/T
  A = [0]*n
  B = [0]*n
  t = np.linspace(0, T, 100)
  A[0] = (1/T)*(integral_0(f, t))

  for k in range(1, n):
    A[k] = (2/T)*integral_1(f, np.cos, k, omega, t)
    B[k] = (2/T)*integral_1(f, np.sin, k, omega, t)

  print("%.8f" % float(A[0]))
  for k in range(1, n):
    if abs(A[k]) > 0.000001:
      if A[k] >= 0:
        print('+', end='')
      print("%.8f" % float(A[k]) + '*' + 'cos(' + str(k) + '*' + str(omega) + '*t)')
  for k in range(1, n):
    if abs(B[k]) > 0.000001:
      if B[k] >= 0:
        print('+', end='')
      print("%.8f" % float(B[k]) + '*' + 'sin(' + str(k) + '*' + str(omega) + '*t)')

T = np.pi/2
fourier_series(f1, T, 10)
