#!/usr/bin/python3

 #####   #####     ##       #    #    #  ######  #    #   ####   #    #
 #    #  #    #   #  #      #    ##   #  #       #    #  #    #  #   #
 #####   #    #  #    #     #    # #  #  #####   #    #  #       ####
 #    #  #####   ######     #    #  # #  #       #    #  #       #  #
 #    #  #   #   #    #     #    #   ##  #       #    #  #    #  #   #
 #####   #    #  #    #     #    #    #  #        ####    ####   #    #

import sys

program = ''
with open(sys.argv[1], 'r') as file:
    for line in file:
        program += line

program_size = len(program)
data = []
for t in range(35000):
    data.append(0)

instruction_pointer = 0
data_pointer = 0
while instruction_pointer < program_size:
    if program[instruction_pointer] == '>':
        data_pointer += 1
    elif program[instruction_pointer] == '<':
        data_pointer -= 1
    elif program[instruction_pointer] == '+':
        data[data_pointer] += 1
    elif program[instruction_pointer] == '-':
        data[data_pointer] -= 1
    elif program[instruction_pointer] == '.':
        print(data[data_pointer], end = '')
    elif program[instruction_pointer] == ',':
        data[data_pointer] = input()
    elif program[instruction_pointer] == '[':
        if data[data_pointer] == 0:
            iptr_after_jump = instruction_pointer
            while program[iptr_after_jump] != ']':
                iptr_after_jump += 1
            instruction_pointer = iptr_after_jump
    elif program[instruction_pointer] == ']':
        if data[data_pointer] != 0:
            iptr_after_jump = instruction_pointer
            while program[iptr_after_jump] != '[':
                iptr_after_jump -= 1
            instruction_pointer = iptr_after_jump

    instruction_pointer += 1
