/*
BFS

1. Begin search by putting the vertex into queue and mark as visited
2. pop the vertex from queue and push all the vertex that is touching it in queue
3. repeat process until there's no vertex in queue

Time Complexity: O(N)
*/

#include <bits/stdc++.h>

using namespace std;

bool visited[9];
vector<int> graph[9];

void BFS(int start){
    //start queue
    queue<int> q;
    q.push(start);

    //mark the visited
    visited[start] = true;

    //repeat until queue is empty
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << ' ';

        for (int i = 0; i < graph[v].size(); i++){
            int y = graph[v][i];
            if (!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main(){
    // node 1
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);
    
    // node 2
    graph[2].push_back(1);
    graph[2].push_back(7);
    
    // node 3
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);
    
    // node  4
    graph[4].push_back(3);
    graph[4].push_back(5);
    
    // node 5
    graph[5].push_back(3);
    graph[5].push_back(4);
    
    // node 6
    graph[6].push_back(7);
    
    // node 7
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);
    
    // node 8
    graph[8].push_back(1);
    graph[8].push_back(7);
    
    BFS(1);
}