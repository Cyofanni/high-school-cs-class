from ortools.sat.python import cp_model

def main():
    model = cp_model.CpModel()

    # Boolean variables
    a = model.new_bool_var("a")

    # Clause 1: (a AND ¬a)
    model.add_bool_and([a, a.Not()])

    solver = cp_model.CpSolver()
    result = solver.Solve(model)

    if result in (cp_model.OPTIMAL, cp_model.FEASIBLE):
        print("SAT solution found:")
        print("a =", solver.Value(a))
    else:
        print("UNSAT")

if __name__ == "__main__":
    main()
