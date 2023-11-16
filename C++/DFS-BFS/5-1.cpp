/*
DFS

1. Begin search by putting the vertex into stack and mark as visited
2. If there's vertex that hasn't been visited from the top of stack, 
    put the vertex into stack and mark as visited
    otherwise, pop the vertex
3. Repeat step 2 until every vertex has been visited

Time Complexity: O(N)
*/
#include <bits/stdc++.h>

using namespace std;

bool visited[9];
vector<int> graph[9];

void DFS(int x){
    //mark visited
    visited[x] = true;
    cout << x << ' ';

    //visit other vertex that is connected recursively
    for (int i = 0; i < graph[x].size(); i++){
        int y = graph[x][i];
        if (!visited[y]) DFS(y);
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
    
    DFS(1);
}