/*
Goal: to minimize the count of operations while making N to 1
1. N = reduce N by 1
2. N = divide N by k (only when N is divisible by k)
*/

#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt = 0;

int main(){
    cin >> n >> k;

    while (true){
        int target = (n/k) *k;
        
        //since decrement counts as 1 operation
        cnt += n - target;
        n = target;

        //if n is smaller than k, then it's no longer divisible
        if (n < k){
            break;
        }

        n /= k;
        cnt += 1;
    }

    cnt += (n-1);
    cout << cnt << '\n'; 
}