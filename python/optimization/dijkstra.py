#Dijkstra’s algorithm

import math
graph = {'s':{'t':10,'y':5},'y':{'t':3,'x':9,'z':2},'z':{'s':7,'x':6},'x':{'z':4},'t':{'x':1,'y':2}}
distances_source = {'s':0,'y':math.inf,'z':math.inf,'x':math.inf,'t':math.inf}
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
  print('current node\'s successors, with costs:', current_node_successors)

  succ_min_distance = math.inf
  for succ in current_node_successors.items():
    succ_key, succ_distance = succ
    distance_source_s_current_node = distances_source[current_node]
    if distance_source_s_current_node + succ_distance < distances_source[succ_key]:
      distances_source[succ_key] = distance_source_s_current_node + succ_distance
      Q[succ_key] = distance_source_s_current_node + succ_distance
    if succ_distance < succ_min_distance:
      succ_min_distance = succ_distance

  print('costs from source, computed so far:', distances_source)
  print()
