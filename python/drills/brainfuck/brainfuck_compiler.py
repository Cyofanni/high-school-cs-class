#!/usr/bin/python3

 #####   #####     ##       #    #    #  ######  #    #   ####   #    #
 #    #  #    #   #  #      #    ##   #  #       #    #  #    #  #   #
 #####   #    #  #    #     #    # #  #  #####   #    #  #       ####
 #    #  #####   ######     #    #  # #  #       #    #  #       #  #
 #    #  #   #   #    #     #    #   ##  #       #    #  #    #  #   #
 #####   #    #  #    #     #    #    #  #        ####    ####   #    #

import sys

program = ''

tokens = ('>', '<', '+', '-', '.', ',', '[', ']')

def keep_token(tk):
    return tk in tokens

program = ''
with open(sys.argv[1], 'r') as file:
    for line in file:
        program += line

filter_tokens = filter(keep_token, program)
program = "".join(list(filter_tokens))

with open(sys.argv[2], 'w') as obj_file:
    program_size = len(program)
    data = []
    for t in range(35000):
        data.append(0)

    obj_file.write('#include <stdio.h>\n')
    obj_file.write('int main() {\n')
    if sys.argv[3] == '-ascii':
        obj_file.write('char data[30000] = {0};\n')
    elif sys.argv[3] == '-ints':
        obj_file.write('int data[30000] = {0};\n')
    
    obj_file.write('int data_pointer = 0;\n')
    
    instruction_pointer = 0
    data_pointer = 0

    while instruction_pointer < program_size:
        if program[instruction_pointer] == '>':
            obj_file.write('data_pointer++;\n');
        elif program[instruction_pointer] == '<':
            obj_file.write('data_pointer--;\n');
        elif program[instruction_pointer] == '+':
            obj_file.write('data[data_pointer]++;\n');
        elif program[instruction_pointer] == '-':
            obj_file.write('data[data_pointer]--;\n');
        elif program[instruction_pointer] == '.':
            if sys.argv[3] == '-ascii':
                obj_file.write('printf("%c", (data[data_pointer]));\n')
            elif sys.argv[3] == '-ints':
                obj_file.write('printf("%d", (data[data_pointer]));\n')
        elif program[instruction_pointer] == ',':
            if sys.argv[3] == '-ascii':
                obj_file.write('scanf("%c", &data[data_pointer]);\n')
            elif sys.argv[3] == '-ints':
                obj_file.write('scanf("%d", &data[data_pointer]);\n')
        elif program[instruction_pointer] == '[':
            obj_file.write('while (data[data_pointer]) {\n')
        elif program[instruction_pointer] == ']':    
            obj_file.write('}\n')
        instruction_pointer += 1

    obj_file.write('return 0;\n')
    obj_file.write('}\n')
