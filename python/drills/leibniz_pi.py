#compute pi with leibniz series

addends_0 = [4 / num for num in range(1, 50000, 4)]
addends_1 = [-4 / num for num in range(3, 50000, 4)]

print(sum(addends_0) + sum(addends_1))
