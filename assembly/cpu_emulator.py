#von neumann machine
class VNM:
    def __init__(self, instr, reg, mem):
        self.instr = instr
        self.reg = reg
        self.mem = mem
        self.IP = 0
        self.cmp_flag = 0
    def inc_IP(self):
        if self.instr[self.IP] == 'LOAD':
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

    def run(self):
        while self.instr[self.IP] != 'HALT':
            if self.instr[self.IP] == 'LOAD':
                op_register = int(self.instr[self.IP + 1][1:])    #e.g. $5
                if self.instr[self.IP + 2][0] == '$':    #load from register
                    reg = self.instr[self.IP + 2][1]
                    op = self.reg[int(reg)]
                elif self.instr[self.IP + 2][0] == '&':    #load from memory location
                    cell = self.instr[self.IP + 2][1:]
                    op = self.mem[int(cell)]
                else:    #load immediate value
                    op = int(self.instr[self.IP + 2])
                self.reg[op_register] = op
            elif self.instr[self.IP] == 'ADD':
                op_register = int(self.instr[self.IP + 1])
                op_immediate_1 = int(self.instr[self.IP + 2])
                op_immediate_2 = int(self.instr[self.IP + 3])
                self.reg[op_register] = op_immediate_1 + op_immediate_2

            self.inc_IP()
    def dump_registers(self):
        print('REGISTERS\' DUMP')
        for i in range(len(self.reg)):
            print('R' + str(i), self.reg[i])
    def dump_memory(self):
        print('MEMORY DUMP')
        for i in range(len(self.mem)):
            print('CELL_' + str(i), self.mem[i])

arch_bits = 8
program = ['LOAD', '$6', '30',
           'LOAD', '$8', '$6',
           'LOAD', '$10', '&122',
           'HALT']
registers = [0] * 16
memory = [0] * 2 ** arch_bits
memory[122] = 1024
machine = VNM(program, registers, memory)
machine.run()
machine.dump_registers()
print()
machine.dump_memory()
