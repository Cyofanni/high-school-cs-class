def ones_complement_list(n, num_bits):
  ones_compl_list = []
  for c in range(num_bits):
      last_bit = n & 1
      ones_compl_list.insert(0, 1 - last_bit)
      n = n >> 1
  return ones_compl_list

def convert_list_to_bin(bin_num_list):
  result = 0
  for i in range(len(bin_num_list) - 1, -1, -1):
    result = result + bin_num_list[i] * 2 ** (len(bin_num_list) - 1 - i)
  return result

def ones_complement(n, num_bits):
  ocl = ones_complement_list(n, num_bits)
  return convert_list_to_bin(ocl)

def twos_complement(n, num_bits):
  return ones_complement(n, num_bits) + 1

def mod_twos_compl(n, num_bits):
  return n & 0x7fffffff

int_max = 0b01111111_11111111_11111111_11111111  #C: INT_MAX (sizeof(int): 4)
print('INT_MAX, 32 bits:', int_max)
print('INT_MAX, 32 bits (bin):', bin(int_max))
integer_overflow_1 = int_max + 1
print('INT_MAX + 1, 32 bits:', integer_overflow_1)
print('INT_MAX + 1, 32 bits (bin):', bin(integer_overflow_1))
print('modulus of INT_MAX + 1 is: ', mod_twos_compl(integer_overflow_1, 31))
print('INT_MAX + 1: INT_MIN is: ', -twos_complement(mod_twos_compl(integer_overflow_1, 31), 31))
int_min = twos_complement(mod_twos_compl(integer_overflow_1, 31), 31)
print('INT_MIN, 32 bits: ', -int_min)
print('INT_MIN, 32 bits: ', bin(int_min))

integer_underflow_1 = int_min - 1
print('INT_MIN - 1, 32 bits (bin)', bin(integer_underflow_1))
print('INT_MIN - 1: 32 bits', integer_underflow_1)

print()
print()

int_max = 0b01111111
print('INT_MAX, 8 bits:', int_max)
print('INT_MAX, 8 bits (bin):', bin(int_max))
integer_overflow_1 = int_max + 1
print('INT_MAX + 1, 8 bits:', integer_overflow_1)
print('INT_MAX + 1, 8 bits (bin):', bin(integer_overflow_1))
print('modulus of INT_MAX + 1 is: ', mod_twos_compl(integer_overflow_1, 7))
print('INT_MAX + 1: INT_MIN is: ', -twos_complement(mod_twos_compl(integer_overflow_1, 7), 7))
int_min = twos_complement(mod_twos_compl(integer_overflow_1, 7), 7)
print('INT_MIN, 8 bits: ', -int_min)
print('INT_MIN, 8 bits: ', bin(int_min))

integer_underflow_1 = int_min - 1
print('INT_MIN - 1, 8 bits (bin)', bin(integer_underflow_1))
print('INT_MIN - 1: 8 bits', integer_underflow_1)
