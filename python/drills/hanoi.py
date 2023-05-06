moves_list = []

def hanoi(num_disks, peg_init, peg_fin, peg_temp,
          peg_init_l, peg_fin_l, peg_temp_l):
    if num_disks != 0:
        hanoi(num_disks - 1, peg_init,
              peg_temp, peg_fin,
              peg_init_l, peg_temp_l, peg_fin_l)

        move_str = 'move disk ' + str(peg_init_l[0]) + ' from ' + str(peg_init) + ' to ' + str(peg_fin)
        print(move_str)
        moves_list.append(move_str)

        peg_fin_l.insert(0, peg_init_l[0])
        peg_init_l.pop(0)

        hanoi(num_disks - 1, peg_temp,
              peg_fin, peg_init,
              peg_temp_l, peg_fin_l, peg_init_l)


n_disks = 4
peg_init_l = [chr(code) for code in range(97, 97 + n_disks)]
peg_temp_l = ['' for i in range(n_disks)]
peg_fin_l = ['' for i in range(n_disks)]

hanoi(n_disks, 1, 3, 2, peg_init_l, peg_fin_l, peg_temp_l)
print('peg_init:', peg_init_l)
print('peg_temp:', list(filter(lambda c: c != '', peg_temp_l)))
print('peg_fin:', list(filter(lambda c: c != '', peg_fin_l)))
num_moves = len(moves_list)
print('#MOVES:', num_moves)
print('#DISKS:', n_disks)
print('#MOVES must be equal to 2^n_disks - 1:', num_moves == 2**n_disks - 1)

