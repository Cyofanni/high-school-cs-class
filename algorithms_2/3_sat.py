def or_vect(b_vals):
  res = False
  for val in b_vals:
    res = res or val
  return res

def and_vect(b_vals):
  res = True
  for val in b_vals:
    res = res and val
  return res

def next_assignment(variables):
  i = len(variables) - 1
  while i >= 0 and variables[i] == True:
    variables[i] = False
    i -= 1
  if i >= 0:
    variables[i] = True

def assign(formula, variables, assignment):
  num_vars = len(variables)
  vars_vals = {}

  #generate dict with assignment (var:val)
  i = 0
  for var in variables:
    vars_vals[var] = assignment[i]
    i += 1

  res = True    #result of () and () and () ...
  for clause in formula:
    vals = []
    for var in clause:
      if var[0] == 'x':    #positive
        vals.append(vars_vals[var])
      elif var[0] == '-':    #negated
        vals.append(not(vars_vals[var[1:]]))
    clause_res = or_vect(vals)    #result of (x or y or z)
    res = res and clause_res

  return res

def three_sat(formula, variables):
  num_vars = len(variables)
  assignment = [False] * len(variables)
  for _ in range(2 ** num_vars):
    print(assignment, end = ' => ')
    print(assign(formula, variables, assignment))
    next_assignment(assignment)

#(x0 or x1 or not(x2)) and (x2 or not(x3) ...) ...
c0 = ['x0', 'x1', '-x2']
c1 = ['x2', '-x3', '-x4']
c2 = ['-x3', 'x4', 'x5']
formula = [c0, c1, c2]
variables = ['x0', 'x1', 'x2', 'x3', 'x4', 'x5']
three_sat(formula, variables)
