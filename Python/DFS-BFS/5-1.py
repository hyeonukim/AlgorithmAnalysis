'''
DFS

1. Begin search by putting the vertex into stack and mark as visited
2. If there's vertex that hasn't been visited from the top of stack, 
    put the vertex into stack and mark as visited
    otherwise, pop the vertex
3. Repeat step 2 until every vertex has been visited

Time Complexity: O(N)
'''

def DFS(graph, v, visited):
    #mark visited
    visited[v] = True
    print(v, end=' ')

    #visit other vertex that is connected recursively
    for i in graph[v]:
        if visited[i] == False:
            DFS(graph, i, visited)

#graph representation in list
graph = [
    [],
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]

#visited array
visited = [False] * 9

DFS(graph, 1, visited)