import text_number_converter as tnc
import sys

num = tnc.text_to_number_b_27(sys.argv[1])
public_key_exp = int(sys.argv[2])
public_key_mod = int(sys.argv[3])

ciphertext = pow(num, public_key_exp, public_key_mod)
print('ciphertext is:', tnc.number_b_27_to_text(ciphertext))

