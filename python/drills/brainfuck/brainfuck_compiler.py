#!/usr/bin/python3

 #####   #####     ##       #    #    #  ######  #    #   ####   #    #
 #    #  #    #   #  #      #    ##   #  #       #    #  #    #  #   #
 #####   #    #  #    #     #    # #  #  #####   #    #  #       ####
 #    #  #####   ######     #    #  # #  #       #    #  #       #  #
 #    #  #   #   #    #     #    #   ##  #       #    #  #    #  #   #
 #####   #    #  #    #     #    #    #  #        ####    ####   #    #

import sys

program = ''

with open(sys.argv[1], 'r') as src_file:
    for line in src_file:
        program += line

with open(sys.argv[2], 'w') as obj_file:
    program_size = len(program)
    data = []
    for t in range(35000):
        data.append(0)

    obj_file.write('#include <stdio.h>\n')
    obj_file.write('int main() {\n')
    obj_file.write('  int data[30000] = {0};\n')
    obj_file.write('  int data_pointer = 0;\n')

    instruction_pointer = 0
    data_pointer = 0
    loop_counter = 0

    while instruction_pointer < program_size:
        if program[instruction_pointer] == '>':
            obj_file.write('  data_pointer++;\n');
        elif program[instruction_pointer] == '<':
            obj_file.write('  data_pointer--;\n');
        elif program[instruction_pointer] == '+':
            obj_file.write('  data[data_pointer]++;\n');
        elif program[instruction_pointer] == '-':
            obj_file.write('  data[data_pointer]--;\n');
        elif program[instruction_pointer] == '.':
            obj_file.write('  printf("%d", (data[data_pointer]));\n')
        elif program[instruction_pointer] == ',':
            obj_file.write('  scanf("%d", &data[data_pointer]);\n')
        elif program[instruction_pointer] == '[':
            obj_file.write('  loop_' + str(loop_counter) + ':\n')
            obj_file.write('    if (data[data_pointer] == 0) {\n')
            obj_file.write('      goto end_loop_' + str(loop_counter) + ';\n')
            obj_file.write('    }\n')
        elif program[instruction_pointer] == ']':
            obj_file.write('  if (data[data_pointer] != 0) {\n')
            obj_file.write('    goto loop_' + str(loop_counter) + ';\n')
            obj_file.write('  }\n')
            obj_file.write('  end_loop_' + str(loop_counter) + ':\n')
            obj_file.write('    ;\n')

        instruction_pointer += 1

    obj_file.write('  return 0;\n')
    obj_file.write('}\n')
