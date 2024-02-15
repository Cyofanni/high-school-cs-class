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

G_1 = {'s':['t'],'t': ['s']}
G_costs_1 = {'s': 0,'t': math.inf}
G_edges_1 = [('s','t',2),('t','s',-4)]
P_1 = {'s':None,'t':None}

G_2 = {'s':['x'],'x':['y'],'y':['x']}
G_costs_2 = {'s':0,'x':math.inf,'y':math.inf}
G_edges_2 = [('s','x',1),('x','y',3),('y','x',-5)]
P_2 = {'s':None,'x':None,'y':None}

res = bellman_ford(G_2, G_costs_2, G_edges_2, P_2)
print(G_costs_2)
print(P_2)
print(res)
