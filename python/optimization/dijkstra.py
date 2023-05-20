#Dijkstra’s algorithm

import math

def extract_min(d):
  min_cost = math.inf
  min_v = None
  for pair in d.items():
    if pair[1] <= min_cost:
      min_cost = pair[1]
      min_v = pair[0]

  d.pop(min_v)
  return min_v

def dijkstra(G, source, preds):
  print(G)
  Q = {}
  for v in G.keys():
    Q[v] = G[v]['cst_sp_src']

  while len(Q) > 0:
    v = extract_min(Q)
    v_succs = G[v].copy()
    v_succs.pop('cst_sp_src')

    for u in v_succs:
      uv_weight = G[v][u]
      v_c = G[v]['cst_sp_src']
      u_c = G[u]['cst_sp_src']
      new_cst_sp_src = v_c + uv_weight
      if v_c + uv_weight < u_c:
        G[u]['cst_sp_src'] = new_cst_sp_src
        preds[u] = v
        Q[u] = new_cst_sp_src

    print(G)

source = 's'
G = {'s':{'r':5,'t':6,'x':3,'cst_sp_src':0},
         'y':{'cst_sp_src':math.inf},
         'r':{'t':2,'cst_sp_src':math.inf},
         't':{'y':3,'x':1,'cst_sp_src':math.inf},
         'x':{'y':9,'cst_sp_src':math.inf}}

pred_sp_src = {'s':None,'y':None,'r':None,'t':None,'x':None}

dijkstra(G, 's', pred_sp_src)

node = 'y'
print('shortest path to node:', node)
shortest_path = [node]
while pred_sp_src[node] != None:
  node = pred_sp_src[node]
  shortest_path.insert(0, node)

print('BEGIN OF PATH', end = ' -> ')
for node in shortest_path:
  print(node, '->', end = ' ')
print('END OF PATH')
