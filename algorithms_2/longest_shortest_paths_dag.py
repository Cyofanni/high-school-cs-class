import math

def longest_path(g_edges, g_weights, src, dst):
    if src == dst:
        return 0
    src_nbs = g_edges[src]    #src's successors
    max_cost = -math.inf
    for nb in src_nbs:    #for each successor
        src_nb_w = g_weights[src + nb]
        #recursive call on successor
        r = src_nb_w + longest_path(g_edges, g_weights, nb, dst)
        if r > max_cost:
            max_cost = r

    return max_cost

def shortest_path(g_edges, g_weights, src, dst):
    if src == dst:
        return 0
    src_nbs = g_edges[src]    #src's successors
    min_cost = math.inf
    for nb in src_nbs:    #for each successor
        src_nb_w = g_weights[src + nb]
        #recursive call on successor
        r = src_nb_w + shortest_path(g_edges, g_weights, nb, dst)
        if r < min_cost:
            min_cost = r

    return min_cost

#DAG 0
adj_list_0 = {'s':['a','b'],
              'b':['c', 'd'],
              'c':[],
              'd':['t'],
              'a':['e','f'],
              'e':['d','t'],
              't':['g'],
              'f':['t','g'],
              'g':[],
              'h':['t']
              }

weights_0 = {'sa':5,
             'sb':1,
             'bc':-8,
             'bd':3,
             'dt':-6,
             'ae':6,
             'af':9,
             'ed':9,
             'et':-16,
             'tg':7,
             'ft':5,
             'fg':2,
             'ht':3
             }

print(longest_path(adj_list_0, weights_0, 's', 't'))
print(shortest_path(adj_list_0, weights_0, 's', 't'))
