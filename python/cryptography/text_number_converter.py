#usage: python3 text_number_converter.py 0 texttoconverttonumber
#       python3 text_number_converter.py 1 98656234986865
import sys

'''
char to number conversion
  ' ' -> 0
  'a' -> 1
  'b' -> 2
  ........
  'z' -> 26
'''
def char_to_number_b_27(c):
    if c == ' ':
        return 0
    return ord(c) - 96  #ord(c) - 97 + 1

def number_to_char(n):
    if n == 0:
        return ' '
    return chr(n + 96)

def text_to_number_b_27(s):
    s_len = len(s)
    i = s_len - 1
    result = 0
    exp = 0
    base = 27
    while i >= 0:
        result += char_to_number_b_27(s[i]) * base**exp
        i -= 1
        exp += 1

    return result

def number_b_27_to_text(n):
    text_result = ''
    if n == 0:
        text_result += ' '
    while n != 0:
        text_result += number_to_char(n % 27)
        n = n // 27
    return text_result[-1::-1]

if len(sys.argv) < 3:
    exit("too few command line arguments")

if int(sys.argv[1]) == 0: #convert text to number
    num = text_to_number_b_27(sys.argv[2])
    print(num)
elif int(sys.argv[1]) == 1: #convert number to text
    text = number_b_27_to_text(int(sys.argv[2]))
    print(text)
else:
    exit("first argument must be either 0 or 1")
