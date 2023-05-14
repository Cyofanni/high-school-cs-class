from matplotlib import pyplot

def is_point_of_M(c, num_iters):
    z = 0
    i = 0
    diverged = False
    while i < num_iters and diverged == False:
        z = z ** 2 + c
        if abs(z - c) > 10 ** 8:
            diverged = True
        i += 1

    return not diverged

#x:[-2, 2], y:[-3, 3], step:0.1, num_iters: 16 --> 2s
#x:[-2, 2], y:[-3, 3], step:0.01, num_iters: 16 --> 16m32s

x = -2
final_x = -x
initial_y = -3
final_y = -initial_y
step = 0.1
num_iters = 16
while x <= final_x:
  y = initial_y
  while y <= final_y:
    if is_point_of_M(complex(x, y), num_iters) == True:
      pyplot.scatter([x], [y], [3], color = 'black')
    y = y + step
  x = x + step
