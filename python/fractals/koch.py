from turtle import *

def koch(side, depth):
    if depth == 0:
        forward(side)
        return
    koch(side / 3, depth - 1)
    left(60)
    koch(side / 3, depth - 1)
    right(120)
    koch(side / 3, depth - 1)
    left(60)
    koch(side / 3, depth - 1)

side = 480
left(60)
koch(side, 4)
right(120)
koch(side, 4)
right(120)
koch(side, 4)

mainloop()
