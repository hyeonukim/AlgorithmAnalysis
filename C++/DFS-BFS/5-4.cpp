/*
count the shortest steps to get to (n,m) from (1,1)
the only path you can take is 1's

EX) 5x6 map
101010
111111
000001
111111
111111 -----------> 10
*/
#include <bits/stdc++.h>

using namespace std;

int n, m;
int graph[1000][1000];

//directions possible
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

//bfs
int bfs(int x, int y){
    //init queue
    queue<pair<int,int>> q;
    q.push({x,y});

    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //check 4 directions
        for (int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            //if out of bounds ignore
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            //if move not possible ignore
            if (graph[nx][ny] == 0) continue;
            //if move possible append to queue
            if (graph[nx][ny] == 1){
                graph[nx][ny] = graph[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
    return graph[n-1][m-1];
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%1d", &graph[i][j]);
        }
    }

    cout << bfs(0,0) << '\n';
}