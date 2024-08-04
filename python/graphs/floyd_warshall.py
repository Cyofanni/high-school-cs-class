import math

def floyd_warshall(g_matrix):
    n = len(g_matrix)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if g_matrix[i][j] > g_matrix[i][k] + g_matrix[k][j]:
                    g_matrix[i][j] = g_matrix[i][k] + g_matrix[k][j]

G_matrix = [[0,3,8,math.inf,-4],
            [math.inf,0,math.inf,1,7],
            [math.inf,4,0,math.inf,math.inf],
            [2,math.inf,-5,0,math.inf],
            [math.inf,math.inf,math.inf,6,0]
            ]

floyd_warshall(G_matrix)
for row in G_matrix:
    print(row)
