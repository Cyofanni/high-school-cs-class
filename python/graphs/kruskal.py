#[[a],[b],[h],[i],[c],[g],[f],[d],[e]]
#[[a],[b],[h,g],[i],[c],[f],[d],[e]]
#[[a],[b],[h,g],[i,c],[f],[d],[e]]
#[[a],[b],[h,g,f],[i,c],[d],[e]]
#[[a,b],[h,g,f],[i,c],[d],[e]]
#[[a,b],[h,g,f,c,i],[d],[e]]
#[[a,b],[h,g,f,c,i,d],[e]]
#[[a,b,h,g,f,c,i,d],[e]]
#[[a,b,h,g,f,c,i,d,e]]

def find_set(sets, v):
    for i in range(len(sets)):
        if v in sets[i]:
            return i
    return -1

def kruskal(g_v, g_e):
    g_e.sort(key = lambda item: item[2])
    sets = []
    A = []
    for v in g_v:
        sets.append([v])
    print(sets)
    for edge in g_e:
        u = edge[0]
        v = edge[1]
        i = find_set(sets, u)
        j = find_set(sets, v)
        if i != j:
            for item in sets[j]:
                sets[i].append(item)
            sets.pop(j)
            print(sets)
            A.append(u + v)
    return A

G_V = {'a','b','h','i','c','g','f','d','e'}

G_E = [('a','b',4),('a','h',8),('b','c',8),
       ('b','h',11),('h','i',7),('h','g',1),
       ('i','g',6),('i','c',2),('c','f',4),
       ('c','d',7),('d','f',14),('f','e',10),
       ('d','e',9),('g','f',2)]

G_V_1 = {'A','B','C','D','E','F','G'}
G_E_1 = [('A','B',7),('A','D',5),('B','C',8),
         ('B','E',7),('B','D',9),('D','E',15),
         ('D','F',6),('E','F',8),('E','G',9),
         ('E','C',5),('F','G',11)]

sp_tree_edges = kruskal(G_V_1, G_E_1)
print(sp_tree_edges)
