class TM:
  def __init__(self, states, init_state, tape, cursor, instructions):
    self.states = states.copy()
    self.state = init_state
    self.tape = tape.copy()
    self.cursor = cursor
    self.instructions = instructions.copy()
  def write(self, symbol):
    self.tape[self.cursor] = symbol
  def left(self):
    self.cursor -= 1
  def right(self):
    self.cursor += 1
  def set_state(self, state):
    self.state = state
  def exec(self):
    while True:
      symbol = self.tape[self.cursor]
      instr_key = (self.state, symbol)
      instr_val = self.instructions[instr_key]
      self.state = instr_val[0]
      if self.state == 'H':
        break
      self.write(instr_val[1])
      if instr_val[2] == 'L':
        self.left()
      elif instr_val[2] == 'R':
        self.right()

#program 1: go back to beginning of string
print('program 1')
states_1 = ['A', 'B']
tape_1 = ['' for i in range(1000)]
tape_1[8] = '0'
tape_1[9] = '1'
tape_1[10] = '0'
tape_1[11] = '1'
tape_1[12] = '1'
tape_1[13] = '0'
tape_1[14] = '1'
tape_1[15] = '1'
instructions_1 ={('A','0'):('A','0','L'),('A','1'):('A','1','L'),
                 ('A',''):('B','','R'),('B','0'):('H'),('B','1'):('H'),
                 ('B',''):('H')}

tm_1 = TM(states_1, 'A', tape_1, 13, instructions_1)
tm_1.exec()
print(tm_1.cursor)
print(tm_1.tape[0:50])

#program 1: successor (decimal)
print('\nprogram 2')
states_2 = ['A', 'B', 'C']
tape_2 = ['' for i in range(1000)]
tape_2[7] = '8'
tape_2[8] = '4'
tape_2[9] = '8'
tape_2[10] = '9'
instructions_2 = {
                  ('A','0'):('B','1','R'),('A','1'):('B','2','R'),
                  ('A','2'):('B','3','R'),('A','3'):('B','4','R'),
                  ('A','4'):('B','5','R'),('A','5'):('B','6','R'),
                  ('A','7'):('B','8','R'),('A','8'):('B','9','R'),
                  ('A','9'):('A','0','L'),('A',''):('B','1','R'),
                  ('B','0'):('B','0','R'),
                  ('B','1'):('H'),
                  ('B','2'):('H'),
                  ('B','3'):('H'),
                  ('B','4'):('H'),
                  ('B','5'):('H'),
                  ('B','6'):('H'),
                  ('B','7'):('H'),
                  ('B','8'):('H'),
                  ('B','9'):('H'),
                  ('B',''):('C','','L'),
                  ('C','0'):('H'),
                  ('C','1'):('H'),
                  ('C','1'):('H'),
                  ('C','2'):('H'),
                  ('C','3'):('H'),
                  ('C','4'):('H'),
                  ('C','5'):('H'),
                  ('C','6'):('H'),
                  ('C','7'):('H'),
                  ('C','8'):('H'),
                  ('C','9'):('H'),
                  ('C',''):('H'),
                 }
tm_2 = TM(states_2, 'A', tape_2, 10, instructions_2)
tm_2.exec()
print(tm_2.tape[0:50])
