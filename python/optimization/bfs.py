import math

G_adj_lists = {
               's': ['r', 'w'],
               'v': ['r'],
               'r': ['s', 'v'],
               'w': ['s', 't', 'x'],
               't': ['w', 'x', 'u'],
               'x': ['w', 't', 'y', 'u'],
               'y': ['x', 'u'],
               'u': ['t', 'x', 'y']
              }

V_colors = {
            's': 'gray', 'r': 'white', 'v': 'white',
            'w': 'white', 't': 'white', 'x': 'white',
            'u': 'white', 'y': 'white'
           }

V_d = {
       's': 0, 'r': math.inf, 'v': math.inf, 'w': math.inf,
       't': math.inf, 'x': math.inf, 'u': math.inf, 'y': math.inf
      }

V_p = {
       's': None, 'r': None, 'v': None, 'w': None,
       't': None, 'x': None, 'u': None, 'y': None
      }

Q = ['s']

while len(Q) > 0:
    u = Q.pop(0)
    u_adjs = G_adj_lists[u]
    for v in u_adjs:
        if V_colors[v] == 'white':
            V_colors[v] = 'gray';
            V_d[v] = V_d[u] + 1
            V_p[v] = u
            Q.append(v)
    V_colors[u] = 'black'
