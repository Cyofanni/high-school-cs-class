G = {
      'u': ['v', 'x'],
      'x': ['v'],
      'v': ['y'],
      'y': ['x'],
      'w': ['y', 'z'],
      'z': ['z']
    }

colors = {
      'u': 'white',
      'x': 'white',
      'v': 'white',
      'y': 'white',
      'w': 'white',
      'z': 'white'
    }

#discovery time
d = {
      'u': 0,
      'x': 0,
      'v': 0,
      'y': 0,
      'w': 0,
      'z': 0
    }

#finishing time
f = {
      'u': 0,
      'x': 0,
      'v': 0,
      'y': 0,
      'w': 0,
      'z': 0
    }

#predecessors
p = {
      'u': None,
      'x': None,
      'v': None,
      'y': None,
      'w': None,
      'z': None
    }

def dfs_visit(n):
  colors[n] = 'gray'
  n_succs = G[n]
  for s in n_succs:
    if colors[s] == 'white':
      p[s] = n
      dfs_visit(s)
  colors[n] = 'black'

def dfs():
  for v in G.keys():
    if colors[v] == 'white':
      dfs_visit(v)

dfs()
print('colors:', colors)
print('predecessors:', p)
