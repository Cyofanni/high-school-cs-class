import text_number_converter as tnc
import sys

num = tnc.text_to_number_b_27(sys.argv[1])
private_key_exp = int(sys.argv[2])
private_key_mod = int(sys.argv[3])

plaintext = pow(num, private_key_exp, private_key_mod)
print('plaintext is:', tnc.number_b_27_to_text(plaintext))

