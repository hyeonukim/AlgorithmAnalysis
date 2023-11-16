/*
count how many groups of 0's are together
EX) 3x3 map
001
110
010 ---------> 3
*/
#include <bits/stdc++.h>

using namespace std;

int n,m;
int graph[1000][1000];

//dfs implementation
bool dfs(int x, int y){
    //if out of bounds, return false
    if (x <= -1 || x >= n || y <= -1 || y >= m) return false;

    //if graph[x][y] is 0, then mark it as visited then recursive dfs
    if (graph[x][y] == 0){
        graph[x][y] = 1;
        dfs(x-1, y);
        dfs(x+1, y);
        dfs(x, y-1);
        dfs(x, y+1);
        return true;
    }

    return false;
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%1d", &graph[i][j]);
        }
    }

    int res = 0;
    
    //start the search on every vertex
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (dfs(i,j) == true){
                res += 1;
            }
        }
    }

    cout << res << '\n';
}