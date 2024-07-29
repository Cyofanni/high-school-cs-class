import math

def extract_min(d):
  min_v = min(d, key = d.get)
  d.pop(min_v)
  return min_v

def prim(g, g_c, g_e, p):
  Q = g_c.copy()
  while len(Q) != 0:
    print(Q)
    u = extract_min(Q)

    for v in g[u]:
      u_v = u + v
      u_v_cost = g_e[u_v]
      if v in Q and u_v_cost < g_c[v]:
        g_c[v] = u_v_cost
        Q[v] = u_v_cost
        p[v] = u

G = {
      'a': ['b','h'],
      'b': ['a','c','h'],
      'h': ['a','b','i','g'],
      'i': ['h','g','c'],
      'c': ['b','i','d','f'],
      'g': ['h','i','f'],
      'f': ['g','c','d','e'],
      'd': ['c','f','e'],
      'e': ['d','f']
    }

G_costs = {
            'a': 0,
            'b': math.inf,
            'h': math.inf,
            'i': math.inf,
            'c': math.inf,
            'g': math.inf,
            'f': math.inf,
            'd': math.inf,
            'e': math.inf
          }

G_edges = {
            'ab': 4,
            'ah': 8,
            'ba': 4,
            'bc': 8,
            'bh': 11,
            'ha': 8,
            'hi': 7,
            'hb': 11,
            'hg': 1,
            'ih': 7,
            'ig': 6,
            'ic': 2,
            'cb': 8,
            'ci': 2,
            'cd': 7,
            'cf': 4,
            'gh': 1,
            'gi': 6,
            'gf': 2,
            'fg': 2,
            'fc': 4,
            'fd': 14,
            'fe': 10,
            'dc': 7,
            'df': 14,
            'de': 9,
            'ed': 9,
            'ef': 10
          }

P = {
      'a': None,
      'b': None,
      'h': None,
      'i': None,
      'c': None,
      'g': None,
      'f': None,
      'd': None,
      'e': None
    }

G_1 = {
        's': ['t','x','v'],
        'v': ['s'],
        'u': ['t'],
        't': ['s','u','z','w'],
        'x': ['y','z','s'],
        'w': ['z','t'],
        'z': ['w','t','x','y'],
        'y': ['z','x']
      }

G_1_costs = {
              's': 0,
              't': math.inf,
              'u': math.inf,
              'v': math.inf,
              'x': math.inf,
              'y': math.inf,
              'w': math.inf,
              'z': math.inf,
            }

G_1_edges = {
              'st': 7,
              'sx': 10,
              'sv': 15,
              'vs': 15,
              'ut': 9,
              'tu': 9,
              'ts': 7,
              'tz': 5,
              'tw': 12,
              'xy': 3,
              'xz': 8,
              'xs': 10,
              'wz': 6,
              'wt': 12,
              'zw': 6,
              'zt': 5,
              'zx': 8,
              'zy': 14,
              'yz': 14,
              'yx': 3
            }

P_1 = {
        's': None,
        't': None,
        'u': None,
        'v': None,
        'x': None,
        'y': None,
        'w': None,
        'z': None
      }

prim(G, G_costs, G_edges, P)
print(P)
