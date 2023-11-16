import math

def bellman_ford(g, g_c, g_e, p):
    num_vert = len(g)
    i = 1
    while i <= num_vert - 1:
      for edge in g_e:
        u = edge[0]
        v = edge[1]
        cost_u_v = edge[2]
        #relaxation
        if g_c[u] + cost_u_v < g_c[v]:
          g_c[v] = g_c[u] + cost_u_v
          p[v] = u
      i += 1

    for edge in g_e:
       u = edge[0]
       v = edge[1]
       cost_u_v = edge[2]
       if g_c[v] > g_c[u] + cost_u_v:
        return True

    return False

G = {
     's':['t','y'],
     't':['x','y','z'],
     'x':['t'],
     'z':['s','x'],
     'y':['x','z']
    }

G_costs = {
           's':0,
           't':math.inf,
           'x':math.inf,
           'z':math.inf,
           'y':math.inf
          }

G_edges = [
           ('t','x',5),
           ('t','y',8),
           ('t','z',-4),
           ('x','t',-2),
           ('y','x',-3),
           ('y','z',9),
           ('z','x',7),
           ('z','s',2),
           ('s','t',6),
           ('s','y',7)
          ]

P = {
     's':None,
     't':None,
     'x':None,
     'y':None,
     'z':None
    }

res = bellman_ford(G, G_costs, G_edges, P)
