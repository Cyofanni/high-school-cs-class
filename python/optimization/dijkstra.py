#Dijkstra’s algorithm

import math
graph = {'s':{'t':10,'y':5},'y':{'t':3,'x':9,'z':2},'z':{'s':7,'x':6},'x':{'z':4},
         't':{'x':1,'y':2}}
distances_source = {'s':0,'y':math.inf,'z':math.inf,'x':math.inf,'t':math.inf}
predecessors_shortest_path = {'s':None,'y':None,'z':None,'x':None,'t':None}
Q = distances_source.copy()

def extract_min_cost_node():
  min_cost = math.inf
  min_pair = None
  for pair in Q.items():
    if pair[1] < min_cost:
      min_cost = pair[1] 
      min_pair = pair
  Q.pop(min_pair[0])
  return min_pair[0]

while len(Q) > 0:
  current_node = extract_min_cost_node()
  print('current node is:', current_node)
  current_node_successors = graph[current_node]

  for succ in current_node_successors.items():
    succ_key, succ_distance = succ
    distance_source_s_current_node = distances_source[current_node]
    if distance_source_s_current_node + succ_distance < distances_source[succ_key]:
      distances_source[succ_key] = distance_source_s_current_node + succ_distance
      predecessors_shortest_path[succ_key] = current_node
      Q[succ_key] = distance_source_s_current_node + succ_distance

  print('costs from source, computed so far:', distances_source)
  print()

node = 'x'
print('shortest path to node:', node)
shortest_path = [node]
while predecessors_shortest_path[node] != None:
  node = predecessors_shortest_path[node]
  shortest_path.insert(0, node)

print('BEGIN OF PATH', end = ' -> ')
for node in shortest_path:
  print(node, '->', end = ' ')
print('END OF PATH')
