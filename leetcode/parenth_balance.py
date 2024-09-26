#https://leetcode.com/problems/valid-parentheses/description/

import sys

def verify_parentheses(expr):
  stack = []
  for c in expr:
    if len(stack) == 0 and (c == ')' or c == ']' or c == '}'):
      return False
    if c == '(' or c == '[' or c == '{':
      stack.append(c)
    elif c == ')':
      if stack[len(stack) - 1] == '(':
        stack.pop()
      else:
        return False
    elif c == ']':
      if stack[len(stack) - 1] == '[':
        stack.pop()
      else:
        return False
    elif c == '}':
      if stack[len(stack) - 1] == '{':
        stack.pop()
      else:
        return False

  return len(stack) == 0

print(verify_parentheses(sys.argv[1]))
