from turtle import *

def cantor_set(depth, side):
  if (depth == 0):
    forward(side)
    return
  cantor_set(depth - 1, side / 3)
  x_curr = pos()[0]
  penup()
  goto(x_curr + side / 3, 0)
  pendown()
  cantor_set(depth - 1, side / 3)

cantor_set(2, 500)
mainloop()
