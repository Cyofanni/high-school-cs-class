from ortools.linear_solver import pywraplp

solver = pywraplp.Solver.CreateSolver("GLOP")

x = solver.NumVar(0, solver.infinity(), "x")
y = solver.NumVar(0, solver.infinity(), "y")

print("Number of variables =", solver.NumVariables())

# Constraint 0: x + 2y <= 14.
solver.Add(x + 2 * y <= 14.0)

# Constraint 1: 3x - y >= 0.
solver.Add(3 * x - y >= 0.0)

# Constraint 2: x - y <= 2.
solver.Add(x - y <= 2.0)

print("Number of constraints =", solver.NumConstraints())

# Objective function: 3x + 4y.
solver.Maximize(3 * x + 4 * y)

print(f"Solving with {solver.SolverVersion()}")
status = solver.Solve()

if status == pywraplp.Solver.OPTIMAL:
    print("Solution:")
    print(f"Objective value = {solver.Objective().Value():0.1f}")
    print(f"x = {x.solution_value():0.1f}")
    print(f"y = {y.solution_value():0.1f}")
else:
    print("The problem does not have an optimal solution.")
