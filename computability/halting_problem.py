#suppose H solves the Halting Problem
def H(P, I):
  '''
  if P halts on I:
     return True
  return False
  '''

def H1(P, I):
  #case 1: P halts on I => loop
  if H(P, I) == True:
    while True:
      pass
  #case 2: P loops on I => halt
  return True

'''
call H1 on itself and an input I =>
  if H1 halts on I, then H1 loops;
  if H1 loops on I, then H1 halts
   => contradiction
'''
