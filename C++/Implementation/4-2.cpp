/*
Write a program that takes an input N which results in N:00:00 to N:59:59
that counts up all the times that includes 3 in any of the time
EX) 0:00:03 count += 1, 0:13:00 count += 1
*/
#include <bits/stdc++.h>

using namespace std;

int n, cnt;

bool check(int i, int j, int z){
    //checks if 3 is in the number
    if (i % 10 == 3 || j % 10 == 3 || j / 10 == 3 || z % 10 == 3 || z / 10 == 3) 
        return true;

    return false;
}

int main(){
    cin >> n;

    for (int i = 0; i <= n; i++){
        for (int j = 0; j < 60; j++){
            for (int z = 0; z < 60; z++){
                if (check(i,j,z)) cnt++;
            }
        }
    }

    cout << cnt << '\n';
}