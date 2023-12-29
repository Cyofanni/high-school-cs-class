class DFA:
    def __init__(self, states, start, acc_states, delta_table):
        self.states = states
        self.state = start
        self.acc_states = acc_states
        self.delta_table = delta_table
    def exec(self, input_str):
        for c in input_str:
            self.state = self.delta_table[(self.state, c)]
        if self.state in self.acc_states:
          return True
        return False

#a1 accepts strings containing at least one occurrence of '01'
states_a1 = {'q0','q1','q2'}
start_a1 = 'q0'
acc_states_a1 = {'q1'}
delta_table_a1 = {('q0','1'):'q0',('q0','0'):'q2',('q2','0'):'q2',
                  ('q2','1'):'q1',('q1','0'):'q1',('q1','1'):'q1'}
a1 = DFA(states_a1, start_a1, acc_states_a1, delta_table_a1)
print('a1 tests')
print('0101010100', end = ' : ')
print(a1.exec('0101010100'))
a1.state = 'q0'
print('11111', end = ' : ')
print(a1.exec('11111'))
a1.state = 'q0'
print('10000001', end = ' : ')
print(a1.exec('10000001'))
a1.state = 'q0'
print('01010101010101', end = ' : ')
print(a1.exec('01010101010101'))
a1.state = 'q0'
print('', end = ' : ')
print(a1.exec(''))

#a2 accepts strings where all 'a' comes before all 'b'
states_a2 = {'q0','q1','q2'}
start_a2 = 'q0'
acc_states_a2 = {'q0', 'q1'}
delta_table_a2 = {('q0','a'):'q0',('q0','b'):'q1',('q1','a'):'q2',
                  ('q1','b'):'q1',('q2','a'):'q2',('q2','b'):'q2'}
a2 = DFA(states_a2, start_a2, acc_states_a2, delta_table_a2)
print('\na2 tests')
print('aba', end = ' : ')
print(a2.exec('aba'))
a2.state = 'q0'
print('', end = ' : ')
print(a2.exec(''))
a2.state = 'q0'
print('aaaaaaaaaaaaaaaaaaaabbbbbbbbb', end = ' : ')
print(a2.exec('aaaaaaaaaaaaaaaaaaaabbbbbbbbb'))
a2.state = 'q0'
print('aaaaaaaaaaaaaaaaaaaabbbbbbbbbabab', end = ' : ')
print(a2.exec('aaaaaaaaaaaaaaaaaaaabbbbbbbbbabab'))
