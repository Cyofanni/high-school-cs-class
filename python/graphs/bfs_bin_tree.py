def bfs(tree, root):
    Q = []
    Q.append(root)
    print(root, end = ' ')
    while len(Q) > 0:
        node = Q.pop(0)
        children = tree[node]
        for child in children:
            Q.append(child)
            print(child, end = ' ')
    print()

t = {
    'W': ['Y', 'S'],
    'Y': ['C', 'Z'],
    'Z': ['L'],
    'S': ['B'],
    'B': ['A'],
    'C': [],
    'L': [],
    'A': []
}

bfs(t, 'W')
