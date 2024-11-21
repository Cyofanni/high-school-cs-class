import math

def extract_min(d):
  min_v = min(d, key = d.get)
  d.pop(min_v)
  return min_v

def dijkstra(g, g_c, g_e, p):
  Q = g_c.copy()
  while len(Q) > 0:
    u = extract_min(Q)
    u_successors = g[u]
    for v in u_successors:
      #if v in Q:
      edge_name = u + v
      edge_cost = g_e[edge_name]
      if g_c[v] > g_c[u] + edge_cost:
        g_c[v] = g_c[u] + edge_cost
        Q[v] = g_c[u] + edge_cost
        p[v] = u

def print_path_rec(p, v):
  if p[v] == None:
    print(v, end = ' ')
    return
  print_path_rec(p, p[v])
  print(v, end = ' ')

def print_path_iter(p, v):
  path = []
  while p[v] != None:
    path.insert(0, v)
    v = p[v]
  path.insert(0, v)
  print(path)

G_0 = {
      's': ['r','t','x'],
      'r': ['t'],
      't': ['y','x'],
      'x': ['y'],
      'y': []
    }

G_costs_0 = {
            's': 0,
            'r': math.inf,
            't': math.inf,
            'x': math.inf,
            'y': math.inf
          }

G_edges_0 = {
            'sr': 5,
            'st': 6,
            'sx': 3,
            'rt': 2,
            'tx': 1,
            'ty': 3,
            'xy': 9
          }

P_0 = {
      's': None,
      'r': None,
      't': None,
      'x': None,
      'y': None
    }

dijkstra(G_0, G_costs_0, G_edges_0, P_0)
print(G_costs_0)
print(P_0)

G_1 = {'A':['B','C'], 'B':['C'], 'C':[]}
G_costs_1 = {'A': 0, 'B': math.inf, 'C': math.inf}
G_edges_1 = {'AB': 5, 'AC': 2, 'BC': -10}
P_1 = {'A': None, 'B': None, 'C': None}
dijkstra(G_1, G_costs_1, G_edges_1, P_1)
print(G_costs_1)
print(P_1)
