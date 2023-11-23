class DFA:
    def __init__(self, Q, start, acc_states, delta_table):
        self.Q = Q
        self.state = start
        self.acc_states = acc_states
        self.delta_table = delta_table
    def exec(self, input_str):
        if len(input_str) == 0:
            return False
        self.state = self.delta_table[self.state + '_' +  input_str[0]]
        if self.state in acc_states:
            return True
        return self.exec(input_str[1:])

Q = {'q0','q1','q2'}
start = 'q0'
acc_states = {'q1'}
delta_table = {'q0_1':'q0','q0_0':'q2','q2_0':'q2',
               'q2_1':'q1','q1_0':'q1','q1_1':'q1'}

a1 = DFA(Q, start, acc_states, delta_table)
print(a1.exec('00000001'))
a1.state = 'q0'
print(a1.exec('11111'))
a1.state = 'q0'
print(a1.exec('10000001'))
a1.state = 'q0'
print(a1.exec('00000101'))
a1.state = 'q0'
print(a1.exec('00000000'))
