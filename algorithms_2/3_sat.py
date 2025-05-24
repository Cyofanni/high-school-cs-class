#compute or of clause
def or_vect(b_vals):
  res = False
  for val in b_vals:
    res = res or val
  return res

#and-aggregate clauses
def and_vect(b_vals):
  res = True
  for val in b_vals:
    res = res and val
  return res

#generate assignments as a binary counter
def next_assignment(variables):
  i = len(variables) - 1
  while i >= 0 and variables[i] == True:
    variables[i] = False
    i -= 1
  if i >= 0:
    variables[i] = True

#apply assignment
def assign(formula, variables, assignment):
  num_vars = len(variables)

  #generate dict with assignment (var:val)
  vars_vals = {}
  i = 0
  for var in variables:
    vars_vals[var] = assignment[i]
    i += 1

  res = True    #final result of: (...) and (...) and (...) ...
  for clause in formula:    #formula is a list of clauses (list of lists)
    #apply values of assignment to single clause
    vals = []
    for var in clause:
      #value depends on variable form (positive or negated)
      if var[0] == 'x':    #positive
        vals.append(vars_vals[var])
      elif var[0] == '-':    #negated
        vals.append(not(vars_vals[var[1:]]))
    clause_res = or_vect(vals)    #evaluate current clause
    res = res and clause_res    #and-accumulate clauses

  return res

#try all assignments
def three_sat(formula, variables):
  num_vars = len(variables)
  assignment = [False] * len(variables)
  for _ in range(2 ** num_vars):
    print(assignment, end = ' => ')    #print current assignment
    print(assign(formula, variables, assignment))    #print result of assignment
    next_assignment(assignment)

#(x0 or x1 or not(x2)) and (x2 or not(x3) ...) ...
c0 = ['x0', 'x1', '-x2']
c1 = ['x2', '-x3', '-x4']
c2 = ['-x3', 'x4', 'x5']
formula = [c0, c1, c2]
variables = ['x0', 'x1', 'x2', 'x3', 'x4', 'x5']
three_sat(formula, variables)
