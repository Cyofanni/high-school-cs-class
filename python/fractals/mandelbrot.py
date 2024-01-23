from matplotlib import pyplot
import time

def is_point_of_M(c, num_iters):
    z = 0
    i = 1
    while i <= num_iters:
        z = z ** 2 + c
        if abs(z - c) > 2:
            return False

        i += 1

    return True

x = -1.5
final_x = 0.5
initial_y = -1
final_y = 1
step = 0.01
num_iters = 20

start_time = time.time()
while x <= final_x:
  y = initial_y
  while y <= final_y:
    if is_point_of_M(complex(x, y), num_iters) == True:
      pyplot.scatter([x], [y], [1], color = 'black')
    y = y + step
  x = x + step

pyplot.show()

print(time.time() - start_time)
