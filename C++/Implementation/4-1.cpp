/*
Goal: a user can input L(left) R(right) U(up) D(down)
If user's input goes out of bounds of NxN space, then it should not move, Otherwise get the output of the final location
EX) in a 5x5 space command is: R R R U D D
then the final output should be '3 4' as (1,1)-(1,2)-(1,3)-(1,4)-(1,4)-(2,4)-(3,4)
*/

#include <bits/stdc++.h>

using namespace std;

int n;
string plans;

//each represents start x,y coordinate
int x = 1, y = 1;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char move_types[4] = {'L', 'R', 'U', 'D'};

int main(){
    
    cin >> n;
    cin.ignore();
    getline(cin, plans);

    //for every move, we check the type of the move and move it temporary
    //if our temporary move is valid (not out of bounds) then x, y = nx, ny
    for (int i = 0; i < plans.size(); i++){
        char move = plans[i];
        int nx = -1, ny = -1;
        for (int j = 0; j < 4; j++){
            if (move == move_types[j]){
                nx = x+dx[j];
                ny = y+dy[j];
            }
        }
        //checks for out of bounds
        if (nx < 1 || nx > n || ny < 1 || ny > n){
            continue;
        }
        x = nx, y = ny;
    }

    cout << x << ' ' << y << '\n';
}