import math

def extract_min(d):
  min_v = min(d, key = d.get)
  d.pop(min_v)
  return min_v

def dijkstra(g, g_c, g_e, p):
  Q = G_costs.copy()
  while len(Q) > 0:
    u = extract_min(Q)
    u_successors = G[u]
    for v in u_successors:
      edge_name = u + v
      edge_cost = g_e[edge_name]
      if G_costs[v] > G_costs[u] + edge_cost:
        G_costs[v] = G_costs[u] + edge_cost
        Q[v] = G_costs[u] + edge_cost
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

G = {
      's': ['r','t','x'],
      'r': ['t'],
      't': ['y','x'],
      'x': ['y'],
      'y': []
    }

G_costs = {
            's': 0,
            'r': math.inf,
            't': math.inf,
            'x': math.inf,
            'y': math.inf
          }

G_edges = {
            'sr': 5,
            'st': 6,
            'sx': 3,
            'rt': 2,
            'tx': 1,
            'ty': 3,
            'tx': 1,
            'xy': 9
          }

P = {
      's': None,
      'r': None,
      't': None,
      'x': None,
      'y': None
    }

dijkstra(G, G_costs, G_edges, P)
print(G_costs)
print(P)
print_path_rec(P, 'y')
print()
print_path_rec(P, 't')
print()
