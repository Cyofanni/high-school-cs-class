import math

G_adj = {
         's': ['t', 'y'],
         't': ['x', 'z', 'y'],
         'y': ['z', 'x'],
         'x': ['t'],
         'z': ['s', 'x']
        }

G_edges_costs = [
                 ('s', 't', 6), ('s', 'y', 7),
                 ('t', 'x', 5), ('t', 'z', -4), ('t', 'y', 8),
                 ('y', 'z', 9), ('y', 'x', -3),
                 ('x', 't', -2),
                 ('z', 's', 2), ('z', 'x', 7)
                ]

G_V_costs = {
             's': 0,
             't': math.inf,
             'y': math.inf,
             'x': math.inf,
             'z': math.inf
            }

preds = {
         's': None,
         't': None,
         'y': None,
         'x': None,
         'z': None
        }

V_size = len(G_adj)

no_neg_cycle = True

for i in range(V_size - 1):
    for edge in G_edges_costs:
        edge_u = edge[0]
        edge_v = edge[1]
        edge_cost = edge[2]
        if G_V_costs[edge_u] + edge_cost < G_V_costs[edge_v]:
            G_V_costs[edge_v] = G_V_costs[edge_u] + edge_cost
            preds[edge_v] = edge_u

for edge in G_edges_costs:
    edge_u = edge[0]
    edge_v = edge[1]
    edge_cost = edge[2]
    if G_V_costs[edge_u] + edge_cost < G_V_costs[edge_v]:
        no_neg_cycle = False
        break

print(G_V_costs)
print('predecessor of s:', preds['s'])
print('predecessor of t:', preds['t'])
print('predecessor of y:', preds['y'])
print('predecessor of x:', preds['x'])
print('predecessor of z:', preds['z'])

print()
if no_neg_cycle == True:
  print('==> no negative cycle detected')
else:
  print('==> negative cycle detected')
