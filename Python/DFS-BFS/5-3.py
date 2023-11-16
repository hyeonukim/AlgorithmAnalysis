'''
count how many groups of 0's are together
EX) 3x3 map
001
110
010 ---------> 3
'''
n,m = map(int, input().split())

graph = []
for i in range(n):
    graph.append(list(map(int, input())))

#dfs implementation
def dfs(x,y):
    #if out of bounds, return false
    if x <= -1 or x >= n or y <= -1 or y >= m:
        return False
    
    #if graph[x][y] is 0, then mark it as visited then recursive dfs
    if graph[x][y] == 0:
        graph[x][y] = 1
        dfs(x-1, y)
        dfs(x, y-1)
        dfs(x+1, y)
        dfs(x, y+1)
        return True
    
    return False

res = 0
#start the search on every vertex
for i in range(n):
    for j in range(m):
        if dfs(i,j) == True:
            res += 1

print(res)