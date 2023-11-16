import turtle

def koch(side, depth):
    if depth == 0:
        turtle.forward(side)
        return
    koch(side / 3, depth - 1)
    turtle.left(60)
    koch(side / 3, depth - 1)
    turtle.right(120)
    koch(side / 3, depth - 1)
    turtle.left(60)
    koch(side / 3, depth - 1)

koch(900, 3)

turtle.mainloop()
