#Dijkstra’s algorithm

import math

def print_costs_sp_src(graph, source):
  for key in graph.keys():
    print('Cost of shortest path with source', source + ', dest', key + ':',
          str(graph[key]['cst_sp_src']) + ' (computed so far)')

def extract_min(d):
  min_v = min(d, key = d.get)
  d.pop(min_v)
  return min_v

def dijkstra(G, source, preds):
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

    print_costs_sp_src(G, 's')
    print("*************************")

source = 's'
G = {
      's':{'r':5,'t':6,'x':3,'cst_sp_src':0},
      'y':{'cst_sp_src':math.inf},
      'r':{'t':2,'cst_sp_src':math.inf},
      't':{'y':3,'x':1,'cst_sp_src':math.inf},
      'x':{'y':9,'cst_sp_src':math.inf}
    }

pred_sp_src = {'s':None,'y':None,'r':None,'t':None,'x':None}

source1 = 's'
G1 = {
      's':{'t':10,'y':5,'cst_sp_src':0},
      't':{'x':1,'y':2,'cst_sp_src':math.inf},
      'y':{'t':3,'x':9,'z':2,'cst_sp_src':math.inf},
      'z':{'s':7,'x':6,'cst_sp_src':math.inf},
      'x':{'z':4,'cst_sp_src':math.inf}
     }

pred_sp_src1 = {'s':None,'t':None,'y':None,'x':None,'z':None}

dijkstra(G1, source1, pred_sp_src1)

for dest in G1.keys():
  dest_v = dest
  shortest_path = [dest_v]
  while dest_v != None:
    dest_v = pred_sp_src1[dest_v]
    if (dest_v != None):
      shortest_path.insert(0, dest_v)

  print('Shortest path', source1, '->', dest, 'is:', shortest_path)
