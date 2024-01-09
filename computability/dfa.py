class DFA:
    def __init__(self, Q, q0, F, delta):
        self.Q = Q.copy()
        self.state = q0
        self.F = F.copy()
        self.delta = delta.copy()
    def exec(self, word):
        for c in word:
            self.state = self.delta[(self.state, c)]
        return self.state in self.F

#a1 accepts strings containing at least one occurrence of '01'
Q_a1 = {'q0','q1','q2'}
q0_a1 = 'q0'
F_a1 = {'q1'}
delta_a1 = {('q0','1'):'q0',('q0','0'):'q2',('q2','0'):'q2',
            ('q2','1'):'q1',('q1','0'):'q1',('q1','1'):'q1'}
a1 = DFA(Q_a1, q0_a1, F_a1, delta_a1)
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
Q_a2 = {'q0','q1','q2'}
q0_a2 = 'q0'
F_a2 = {'q0', 'q1'}
delta_a2 = {('q0','a'):'q0',('q0','b'):'q1',('q1','a'):'q2',
            ('q1','b'):'q1',('q2','a'):'q2',('q2','b'):'q2'}
a2 = DFA(Q_a2, q0_a2, F_a2, delta_a2)
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

#a3 accepts strings where ending with an odd number of '1'
Q_a3 = {'q0','q1'}
q0_a3 = 'q0'
F_a3 = {'q1'}
delta_a3 = {('q0','0'):'q0',('q0','1'):'q1',('q1','0'):'q0',
            ('q1','1'):'q0'}
a3 = DFA(Q_a3, q0_a3, F_a3, delta_a3)
print('\na3 tests')
print('', end = ' : ')
print(a3.exec(''))
a3.state = 'q0'
print('0101', end = ' : ')
print(a3.exec('0101'))
a3.state = 'q0'
print('111', end = ' : ')
print(a3.exec('111'))
a3.state = 'q0'
print('1110011', end = ' : ')
print(a3.exec('1110011'))
a3.state = 'q0'
print('01011', end = ' : ')
print(a3.exec('01011'))
