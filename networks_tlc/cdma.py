#example taken from Tanenbaum's Computer Networks
import numpy as np

def negate_chipcode(chipcode):
  return -1 * chipcode

def norm_inner_prod(S, T):
  return (1/len(S)) * sum(S * T)

#ST1_chipcode = np.array([-1, -1, -1, 1, 1, -1, 1, 1])
#ST2_chipcode = np.array([-1, -1, 1, -1, 1, 1, 1, -1])
#ST3_chipcode = np.array([-1, 1, -1, 1, 1, 1, -1, -1])
#ST4_chipcode = np.array([-1, 1, -1, -1, -1, -1, 1, -1])

ST1_chipcode = np.array([1, 1, 1, 1, 1, 1, 1, 1])
ST2_chipcode = np.array([1, -1, 1, -1, 1, -1, 1, -1])
ST3_chipcode = np.array([1, 1, -1, -1, 1, 1, -1, -1])
ST4_chipcode = np.array([1, -1, -1, 1, 1, -1, -1, 1])

#check orthogonality
print('check orthogonality between chipcode pairs')
print(norm_inner_prod(ST1_chipcode, ST2_chipcode))
print(norm_inner_prod(ST1_chipcode, ST3_chipcode))
print(norm_inner_prod(ST1_chipcode, ST4_chipcode))
print(norm_inner_prod(ST2_chipcode, ST3_chipcode))
print(norm_inner_prod(ST2_chipcode, ST4_chipcode))
print(norm_inner_prod(ST3_chipcode, ST4_chipcode))

#S: station is silent
#ST1 transmits the bit sequence: S S 1 1 1 1 1 0
#ST2 transmits the bit sequence: S 1 0 0 1 1 1 S
#ST3 transmits the bit sequence: 1 1 S 1 1 0 1 1
#ST4 transmits the bit sequence: S S S S 1 1 1 0

signal_1 = ST3_chipcode #ST3 transmits its own chipcode (alone)
signal_2 = ST2_chipcode + ST3_chipcode #ST3 transmits its own chipcode
signal_3 = ST1_chipcode + negate_chipcode(ST2_chipcode) #ST3 is silent
signal_4 = ST1_chipcode + negate_chipcode(ST2_chipcode) + \
           ST3_chipcode #ST3 transmits its own chipcode
signal_5 = ST1_chipcode + ST2_chipcode + ST3_chipcode + \
           ST4_chipcode #ST3 transmits its own chipcode
signal_6 = ST1_chipcode + ST2_chipcode + \
           negate_chipcode(ST3_chipcode) + ST4_chipcode #ST3 transmits its own chipcode, negated
signal_7 = ST1_chipcode + ST2_chipcode + \
           ST3_chipcode + ST4_chipcode
signal_8 = negate_chipcode(ST1_chipcode) + ST3_chipcode + \
           + negate_chipcode(ST4_chipcode)

print()
print("extracted ST1's bits")
print(norm_inner_prod(signal_1, ST1_chipcode), end = ' ')
print(norm_inner_prod(signal_2, ST1_chipcode), end = ' ')
print(norm_inner_prod(signal_3, ST1_chipcode), end = ' ')
print(norm_inner_prod(signal_4, ST1_chipcode), end = ' ')
print(norm_inner_prod(signal_5, ST1_chipcode), end = ' ')
print(norm_inner_prod(signal_6, ST1_chipcode), end = ' ')
print(norm_inner_prod(signal_7, ST1_chipcode), end = ' ')
print(norm_inner_prod(signal_8, ST1_chipcode), end = '\n')

print()
print("extracted ST2's bits")
print(norm_inner_prod(signal_1, ST2_chipcode), end = ' ')
print(norm_inner_prod(signal_2, ST2_chipcode), end = ' ')
print(norm_inner_prod(signal_3, ST2_chipcode), end = ' ')
print(norm_inner_prod(signal_4, ST2_chipcode), end = ' ')
print(norm_inner_prod(signal_5, ST2_chipcode), end = ' ')
print(norm_inner_prod(signal_6, ST2_chipcode), end = ' ')
print(norm_inner_prod(signal_7, ST2_chipcode), end = ' ')
print(norm_inner_prod(signal_8, ST2_chipcode), end = '\n')

print()
print("extracted ST3's bits")
print(norm_inner_prod(signal_1, ST3_chipcode), end = ' ')
print(norm_inner_prod(signal_2, ST3_chipcode), end = ' ')
print(norm_inner_prod(signal_3, ST3_chipcode), end = ' ')
print(norm_inner_prod(signal_4, ST3_chipcode), end = ' ')
print(norm_inner_prod(signal_5, ST3_chipcode), end = ' ')
print(norm_inner_prod(signal_6, ST3_chipcode), end = ' ')
print(norm_inner_prod(signal_7, ST3_chipcode), end = ' ')
print(norm_inner_prod(signal_8, ST3_chipcode), end = '\n')

print()
print("extracted ST4's bits")
print(norm_inner_prod(signal_1, ST4_chipcode), end = ' ')
print(norm_inner_prod(signal_2, ST4_chipcode), end = ' ')
print(norm_inner_prod(signal_3, ST4_chipcode), end = ' ')
print(norm_inner_prod(signal_4, ST4_chipcode), end = ' ')
print(norm_inner_prod(signal_5, ST4_chipcode), end = ' ')
print(norm_inner_prod(signal_6, ST4_chipcode), end = ' ')
print(norm_inner_prod(signal_7, ST4_chipcode), end = ' ')
print(norm_inner_prod(signal_8, ST4_chipcode), end = '\n')
