operators = ['+', '*', '-', '/']

def rpn_eval(expr):
  stack = []
  for token in expr:
    if token not in operators:
      stack.append(token)
    else:
      if token == '+':
        ans = stack.pop()
        ans += stack.pop()
      elif token == '*':
        ans = stack.pop()
        ans *= stack.pop()
      elif token == '-':
        ans = stack[len(stack) - 2]
        ans -= stack.pop()
        stack.pop()
      elif token == '/':
        ans = stack[len(stack) - 2]
        ans /= stack.pop()
        stack.pop()
      stack.append(ans)

  return stack[0]

print(rpn_eval([5, 10, '/']))
