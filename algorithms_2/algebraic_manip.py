def eval_expr(expr, root):
    if root == None:
        return
    if type(root) == int:
        return root
    if root[0] == '+':
        return eval_expr(expr, expr[root][0]) + \
               eval_expr(expr, expr[root][1])
    if root[0] == '*':
        return eval_expr(expr, expr[root][0]) * \
               eval_expr(expr, expr[root][1])

#7 * 9 + 10 * 100
expr_0 = {
           '+0':['*0','*1'],
           '*0':[7,9],
           '*1':[10,100]
         }

#2 * 3 + 9 + 6 + 4 * 8
expr_1 = {
           '*0':[2,3],
           '+0':['*0',9],
           '+1':['+0',6],
           '*1':[4,8],
           '+2':['+1','*1']
         }

print(eval_expr(expr_0, '+0'))
print(eval_expr(expr_1, '+2'))

i = 0
def diff(expr, root, ddx_expr):
    global i
    i += 1
    if type(root) == int:
        return 0
    if root == 'x':
        return 1
    if root[0] == '+':
        new_key = '+' + str(i)
        ddx_expr[new_key] = [diff(expr, expr[root][0], ddx_expr), \
                             diff(expr, expr[root][1], ddx_expr)]
        return new_key
    if root[0] == '*':
        new_key_1 = '+' + str(i)
        new_key_2 = '*' + str(i + 1)
        new_key_3 = '*' + str(i + 2)
        ddx_expr[new_key_1] = [new_key_2, new_key_3]
        ddx_expr[new_key_2] = [diff(expr, expr[root][0], ddx_expr), \
                               expr[root][1]]
        ddx_expr[new_key_3] = [expr[root][0], diff(expr, expr[root][1], \
                               ddx_expr)]
        return new_key_1
    if root[0:3] == 'sin':
        new_key_1 = '*' + str(i)
        new_key_2 = 'cos' + str(i)
        sin_arg = expr[root][0]
        ddx_expr[new_key_2] = [sin_arg, None]
        ddx_expr[new_key_1] = [new_key_2, diff(expr, sin_arg, ddx_expr)]
        if sin_arg != 'x':
            ddx_expr[sin_arg] = expr[sin_arg]
        return new_key_1

def print_infix(expr, root):
    if root == None:
        return
    if type(root) == int or root =='x':
        print(root, end = '')
        return
    print_infix(expr, expr[root][0])
    if (root[0:3] == 'sin' or root[0:3] == 'cos'):
        print(root[0:3], end = '')
    else:
        print(root[0], end = '')
    print_infix(expr, expr[root][1])

#2 + x
print()
i = 0
expr_2 = {'+0':[2,'x']}
ddx_expr_2 = {}
print(diff(expr_2, '+0', ddx_expr_2))
print(ddx_expr_2)

#2 * x
print()
i = 0
expr_3 = {'*0':[2,'x']}
ddx_expr_3 = {}
print(diff(expr_3, '*0', ddx_expr_3))
print(ddx_expr_3)
print()

#x * x
i = 0
expr_4 = {'*0':['x','x']}
ddx_expr_4 = {}
root = diff(expr_4, '*0', ddx_expr_4)
print(root)
print(ddx_expr_4)

#3 * x + 2 * x
print()
i = 0
expr_5 = {
          '*0':[3,'x'],
          '*1':[2,'x'],
          '+0':['*0','*1']
         }
ddx_expr_5 = {}
root = diff(expr_5, '+0', ddx_expr_5)
print(root)
print(ddx_expr_5)
print_infix(expr_5, '+0')
print()
print_infix(ddx_expr_5, root)
print()

#sin(x)
print()
i = 0
expr_6 = {'sin0':['x',None]}
ddx_expr_6 = {}
root = diff(expr_6, 'sin0', ddx_expr_6)
print(root)
print(ddx_expr_6)
print_infix(expr_6, 'sin0')
print()
print_infix(ddx_expr_6, root)
print()

#sin(2 * x)
print()
i = 0
expr_7 = {
          'sin0':['*0',None],
          '*0':[2,'x']
         }
print(expr_7)
ddx_expr_7 = {}
root = diff(expr_7, 'sin0', ddx_expr_7)
print(root)
print(ddx_expr_7)
print_infix(expr_7, 'sin0')
print()
print_infix(ddx_expr_7, root)
print()
