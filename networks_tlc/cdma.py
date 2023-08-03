#example taken from Tanenbaum's Computer Networks
import numpy as np

def negate_chipcode(chipcode):
  chipcode_neg = np.zeros(len(chipcode))
  for i in range(len(chipcode)):
    chipcode_neg[i] = -1 * chipcode[i]

  return chipcode_neg

def norm_inner_prod(S, T):
  return (1/len(S)) * sum(S * T)

ST1_chipcode = np.array([-1, -1, -1, 1, 1, -1, 1, 1])
ST2_chipcode = np.array([-1, -1, 1, -1, 1, 1, 1, -1])
ST3_chipcode = np.array([-1, 1, -1, 1, 1, 1, -1, -1])
ST4_chipcode = np.array([-1, 1, -1, -1, -1, -1, 1, -1])

#check orthogonality
print('check orthogonality between chipcode pairs')
print(norm_inner_prod(ST1_chipcode, ST2_chipcode))
print(norm_inner_prod(ST1_chipcode, ST3_chipcode))
print(norm_inner_prod(ST1_chipcode, ST4_chipcode))
print(norm_inner_prod(ST2_chipcode, ST3_chipcode))
print(norm_inner_prod(ST2_chipcode, ST4_chipcode))
print(norm_inner_prod(ST3_chipcode, ST4_chipcode))

#ST3 trasmits the bit sequence: 1 1 silent 1 1 - 1
signal_1 = ST3_chipcode                    #ST3 trasmits its own chipcode (alone)
signal_2 = ST2_chipcode + ST3_chipcode     #ST3 tramits its own chipcode
signal_3 = ST1_chipcode + negate_chipcode(ST2_chipcode) #ST3 is silent
signal_4 = ST1_chipcode + negate_chipcode(ST2_chipcode) + ST3_chipcode  #ST3 transmits its own chipcode
signal_5 = ST1_chipcode + ST2_chipcode + ST3_chipcode + ST4_chipcode    #ST3 transmits its own chipcode
signal_6 = ST1_chipcode + ST2_chipcode + negate_chipcode(ST3_chipcode) + ST4_chipcode  #ST3 transmits its own chipcode, negated

print("extracted ST3's bits")
print(norm_inner_prod(signal_1, ST3_chipcode))
print(norm_inner_prod(signal_2, ST3_chipcode))
print(norm_inner_prod(signal_3, ST3_chipcode))
print(norm_inner_prod(signal_4, ST3_chipcode))
print(norm_inner_prod(signal_5, ST3_chipcode))
print(norm_inner_prod(signal_6, ST3_chipcode))
