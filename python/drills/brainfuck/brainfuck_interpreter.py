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
memory_cells = []
for t in range(35000):
    memory_cells.append(0)

instruction_pointer = 0
data_pointer = 0
while instruction_pointer < program_size:
    if program[instruction_pointer] == '>':
        data_pointer += 1
    elif program[instruction_pointer] == '<':
        data_pointer -= 1
    elif program[instruction_pointer] == '+':
        memory_cells[data_pointer] += 1
    elif program[instruction_pointer] == '-':
        memory_cells[data_pointer] -= 1
    elif program[instruction_pointer] == '.':
        print(memory_cells[data_pointer], end = '')
    elif program[instruction_pointer] == ',':
        memory_cells[data_pointer] = input()
    elif program[instruction_pointer] == '[':
        if memory_cells[data_pointer] == 0:
            jump_at_instruction = instruction_pointer
            while program[jump_at_instruction] != ']':
                jump_at_instruction += 1
            instruction_pointer = jump_at_instruction
    elif program[instruction_pointer] == ']':
        if memory_cells[data_pointer] != 0:
            jump_at_instruction = instruction_pointer
            while program[jump_at_instruction] != '[':
                jump_at_instruction -= 1
            instruction_pointer = jump_at_instruction

    instruction_pointer += 1



