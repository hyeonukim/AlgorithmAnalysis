'''
count the shortest steps to get to (n,m) from (1,1)
the only path you can take is 1's

EX) 5x6 map
101010
111111
000001
111111
111111 -----------> 10
'''
from collections import deque

n, m = map(int, input().split())

graph = []
for i in range(n):
    graph.append(list(map(int,input())))

#directions possible
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

#bfs
def bfs(x,y):
    #init queue    
    q = deque()
    q.append((x,y))

    while q:
        x,y = q.popleft()
        #check 4 directions
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]

            #if out of bounds ignore
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            #if move not possible ignore
            if graph[nx][ny] == 0:
                continue
            #if move possible append to queue
            if graph[nx][ny] == 1:
                graph[nx][ny] = graph[x][y] + 1
                q.append((nx,ny))

    return graph[n-1][m-1]

print(bfs(0,0))