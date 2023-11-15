/*
Input: 
   N * M map
   x, y, dir   coordinate of the player, direction player is facing (0 = North, 1 = East, 2 = South, 3 = West)
   1, 0 filled with N * M map where 1 = sea, 0 = land

Output:
   How many land did player get to touch/move to

Rules:
   1. Check if Left of player's direction is viable
   2. If player hasn't been to, move to, Otherwise rotate only
   3. If player has been to all 4 directions or been not able to go to go back 1. If player can not move back then return
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, direction;

int d[50][50];

int arr[50][50];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void turn_left() {
    direction -= 1;
    if (direction == -1){
        direction = 3;
    }
}

int main(){
    cin >> n >> m;
    
    cin >> x >> y >> direction;
    d[x][y] = 1;

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }

    int cnt = 1;
    int turn_time = 0;

    while (true){
        //step 1
        turn_left();
        int nx = x+dx[direction];
        int ny = y+dy[direction];

        //step 2
        if (d[nx][ny] == 0 && arr[nx][ny] == 0){
            d[nx][ny] = 1;
            x = nx;
            y = ny;
            cnt += 1;
            turn_time = 0;
            continue;
        }

        else{
            turn_time += 1;
        }

        //step 3 
        if (turn_time == 4){
            nx = x-dx[direction];
            ny = y-dy[direction];

            if (arr[nx][ny] == 0){
                x = nx;
                y = ny;
            }

            else{
                break;
            }
            turn_time = 0;
        }
    }

    cout << cnt << '\n';


}