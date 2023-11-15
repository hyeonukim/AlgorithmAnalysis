/*
check how many ways knights can go
EX) input: a1 output: 2, since it can only go to c2 or b3
*/

#include <bits/stdc++.h>

using namespace std;

string n;

int dx[] = {1,-1,2,2,1,-1,-2,-2};
int dy[] = {2,2,1,-1,-2,-2,1,-1};

int main(){
    cin >> n;
    int row = n[1] - '0';
    int col = n[0] - 'a' + 1;

    int res = 0;

    for (int i = 0; i < 8 ; i++){
        int nextrow = row+dx[i];
        int nextcol = col+dy[i];
        if (1 <= nextrow && nextrow <= 8 && 1 <= nextcol && nextcol <= 8){
            res++;
        }
    }
    
    cout << res << '\n';
}