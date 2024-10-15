peg1 = ['________', '_______', '______', '_____', '____', '___', '__', '_']
peg2 = []
peg3 = []
peg3_solution = peg1.copy()
smallest_disk_peg = 1
pick_smallest_disk = True
direction = 'left'
move_counter = 0

if len(peg1) % 2 == 0:
    direction = 'right'

while peg3 != peg3_solution:
    #print(peg1, '  ', peg2, '  ', peg3)
    #print()
    if pick_smallest_disk == True:
        if smallest_disk_peg == 1:
            smallest_disk = peg1.pop()
            if direction == 'left':
                peg3.append(smallest_disk)
                smallest_disk_peg = 3
                print('move disk from peg 1 to peg 3')
            else:
                peg2.append(smallest_disk)
                smallest_disk_peg = 2
                print('move disk from peg 1 to peg 2')
        elif smallest_disk_peg == 2:
            smallest_disk = peg2.pop()
            if direction == 'left':
                peg1.append(smallest_disk)
                smallest_disk_peg = 1
                print('move disk from peg 2 to peg 1')
            else:
                peg3.append(smallest_disk)
                smallest_disk_peg = 3
                print('move disk from peg 2 to peg 3')
        elif smallest_disk_peg == 3:
            smallest_disk = peg3.pop()
            if direction == 'left':
                peg2.append(smallest_disk)
                smallest_disk_peg = 2
                print('move disk from peg 3 to peg 2')
            else:
                peg1.append(smallest_disk)
                smallest_disk_peg = 1
                print('move disk from peg 3 to peg 1')
    else:
        if smallest_disk_peg == 1:
            if len(peg2) > 0 and len(peg3) > 0:
                top_disk_not_smallest_peg2 = peg2[len(peg2) - 1]
                top_disk_not_smallest_peg3 = peg3[len(peg3) - 1]
                if top_disk_not_smallest_peg2 < top_disk_not_smallest_peg3:
                    peg2.pop()
                    peg3.append(top_disk_not_smallest_peg2)
                    print('move disk from peg 2 to peg 3')
                else:
                    peg3.pop()
                    peg2.append(top_disk_not_smallest_peg3)
                    print('move disk from peg 3 to peg 2')
            elif len(peg2) == 0:
                peg2.append(peg3.pop())
                print('move disk from peg 3 to peg 2')
            elif len(peg3) == 0:
                peg3.append(peg2.pop())
                print('move disk from peg 2 to peg 3')
        elif smallest_disk_peg == 2:
            if len(peg1) > 0 and len(peg3) > 0:
                top_disk_not_smallest_peg1 = peg1[len(peg1) - 1]
                top_disk_not_smallest_peg3 = peg3[len(peg3) - 1]
                if top_disk_not_smallest_peg1 < top_disk_not_smallest_peg3:
                    peg1.pop()
                    peg3.append(top_disk_not_smallest_peg1)
                    print('move disk from peg 1 to peg 3')
                else:
                    peg3.pop()
                    peg1.append(top_disk_not_smallest_peg3)
                    print('move disk from peg 3 to peg 1')
            elif len(peg1) == 0:
                peg1.append(peg3.pop())
                print('move disk from peg 3 to peg 1')
            elif len(peg3) == 0:
                peg3.append(peg1.pop())
                print('move disk from peg 1 to peg 3')
        elif smallest_disk_peg == 3:
            if len(peg1) > 0 and len(peg2) > 0:
                top_disk_not_smallest_peg1 = peg1[len(peg1) - 1]
                top_disk_not_smallest_peg2 = peg2[len(peg2) - 1]
                if top_disk_not_smallest_peg1 < top_disk_not_smallest_peg2:
                    peg1.pop()
                    peg2.append(top_disk_not_smallest_peg1)
                    print('move disk from peg 1 to peg 2')
                else:
                    peg2.pop()
                    peg1.append(top_disk_not_smallest_peg2)
                    print('move disk from peg 2 to peg 1')
            elif len(peg1) == 0:
                peg1.append(peg2.pop())
                print('move disk from peg 2 to peg 1')
            elif len(peg2) == 0:
                peg2.append(peg1.pop())
                print('move disk from peg 1 to peg 2')

    pick_smallest_disk = not(pick_smallest_disk)
    move_counter += 1

#print(peg1, '  ', peg2, '  ', peg3)
print('--->', move_counter, 'moves')
