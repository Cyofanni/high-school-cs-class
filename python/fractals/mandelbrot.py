from matplotlib import pyplot

def is_in_mandelbrot(c):
  z = 0
  for i in range(20):
    z = z ** 2 + c
    if abs(z - c) > 2:
      return False
  return True

def draw_mandelbrot_escape_time(step):
  x_init = -2
  x_final = 0.5
  y_init = -1.2
  y_final = 1.2

  x = x_init
  while x <= x_final:
    y = y_init
    while y <= y_final:
      if is_in_mandelbrot(complex(x, y)) == True:
        pyplot.scatter([x], [y], 1, color = 'black')
      y += step
    x += step

draw_mandelbrot_escape_time(0.01)
