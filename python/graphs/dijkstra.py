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

G = {'s':['t','y'],
     'y':['x','z','t'],
     'z':['x','s'],
     't':['x','y'],
     'x':['z']
    }

G_costs = {'s':0,
           't':math.inf,
           'x':math.inf,
           'z':math.inf,
           'y':math.inf
          }

G_edges = {'st':10,
           'sy':5,
           'yx':9,
           'yz':2,
           'yt':3,
           'zx':6,
           'zs':7,
           'tx':1,
           'ty':2,
           'xz':4
          }

P = {'s':None,
     't':None,
     'x':None,
     'y':None,
     'z':None
    }
