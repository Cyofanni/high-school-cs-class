#MINI architecture simulator

import sys

class MINI_CPU:
    def __init__(self, instr, reg, mem):
        self.instr = instr
        self.reg = reg
        self.mem = mem
        self.IP = 0
        self.cmp_flag = 0
    def inc_IP(self):
        if self.instr[self.IP] == 'LOAD' or self.instr[self.IP] == 'STORE' \
           or self.instr[self.IP] == 'CMP':
            self.IP += 3
        elif self.instr[self.IP] == 'ADD':
            self.IP += 4
        elif self.instr[self.IP] == 'JMP':
            op_instr_addr = int(self.instr[self.IP + 1])
            self.IP = op_instr_addr
        elif self.instr[self.IP] == 'JMPG':
            if self.cmp_flag > 0:
                op_instr_addr = int(self.instr[self.IP + 1])
                self.IP = op_instr_addr
            else:
                self.IP += 2
        elif self.instr[self.IP] == 'JMPE':
            if self.cmp_flag == 0:
                op_instr_addr = int(self.instr[self.IP + 1])
                self.IP = op_instr_addr
            else:
                self.IP += 2
        elif self.instr[self.IP] == 'JMPGE':
            if self.cmp_flag >= 0:
                op_instr_addr = int(self.instr[self.IP + 1])
                self.IP = op_instr_addr
            else:
                self.IP += 2
        elif self.instr[self.IP] == 'JMPL':
            if self.cmp_flag < 0:
                op_instr_addr = int(self.instr[self.IP + 1])
                self.IP = op_instr_addr
            else:
                self.IP += 2
        elif self.instr[self.IP] == 'JMPLE':
            if self.cmp_flag <= 0:
                op_instr_addr = int(self.instr[self.IP + 1])
                self.IP = op_instr_addr
            else:
                self.IP += 2

    def run(self):
        while self.instr[self.IP] != 'HALT':
            if self.instr[self.IP] == 'LOAD':
                op_register = int(self.instr[self.IP + 1][1:])    #e.g. $5
                if self.instr[self.IP + 2][0] == '$':    #load from register
                    reg = self.instr[self.IP + 2][1]
                    op = self.reg[int(reg)]
                elif self.instr[self.IP + 2][0] == '&':    #load from memory location
                    mem_cell = self.instr[self.IP + 2][1:]
                    op = self.mem[int(mem_cell)]
                else:    #load immediate value
                    op = int(self.instr[self.IP + 2])
                self.reg[op_register] = op
            elif self.instr[self.IP] == 'STORE':
                op_register = int(self.instr[self.IP + 1][1:])    #e.g. $5
                mem_cell = int(self.instr[self.IP + 2][1:])    #e.g. &230
                self.mem[mem_cell] = self.reg[op_register]
            elif self.instr[self.IP] == 'ADD':
                reg_dest = int(self.instr[self.IP + 1][1:])
                #add values of 2 registers, store result into a register
                if self.instr[self.IP + 2][0] == '$':
                    reg_src_1 = int(self.instr[self.IP + 2][1:])
                    reg_src_2 = int(self.instr[self.IP + 3][1:])
                    self.reg[reg_dest] = self.reg[reg_src_1] + self.reg[reg_src_2]
                else:
                    imm_src_1 = int(self.instr[self.IP + 2])
                    imm_src_2 = int(self.instr[self.IP + 3])
                    self.reg[reg_dest] = imm_src_1 + imm_src_2
            elif self.instr[self.IP] == 'CMP':
                #compare values of 2 registers, store result in flag
                reg_1 = int(self.instr[self.IP + 1][1:])
                reg_2 = int(self.instr[self.IP + 2][1:])
                self.cmp_flag = reg_1 - reg_2

            self.inc_IP()

    def dump_registers(self):
        print('REGISTERS\' DUMP:')
        for i in range(len(self.reg)):
            print('R' + str(i), self.reg[i])
        print('FLAGS:')
        print(self.cmp_flag)
    def dump_memory(self):
        print('MEMORY DUMP:')
        for i in range(len(self.mem)):
            print('CELL_' + str(i), self.mem[i])


f = open(sys.argv[1])
program = []
for line in f:
    program.append(line.split(' '))

program_flat = [item.rstrip() for line in program for item in line]
print(program_flat)
arch_bits = 8
registers = [0] * 16
memory = [0] * 2 ** arch_bits
machine = MINI_CPU(program_flat, registers, memory)
machine.run()
machine.dump_registers()
print()
machine.dump_memory()
