'''
BFS

1. Begin search by putting the vertex into queue and mark as visited
2. pop the vertex from queue and push all the vertex that is touching it in queue
3. repeat process until there's no vertex in queue

Time Complexity: O(N)
'''

from collections import deque

def BFS(graph, start, visited):
    #start queue
    queue = deque([start])

    #mark the visited
    visited[start] = True
    
    #repeat until queue is empty
    while queue:
        v = queue.popleft()
        print(v, end=' ')

        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

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

BFS(graph, 1, visited)
