/*
A, B each are playing bowling. They are trying to choose different weight of bowling bowl from each other.
There are total N bowling balls. Each weighing from range of 1-M kg. There may be some balls that weight the same.
Write a code that calculates how many combinations A,B can have

EX) N = 5, M = 3, arr = 1,3,2,3,2

ans = (1,3), (1,2), (1,3), (1,2), (3,2), (3,2), (2,3), (3,2) - therefore there are 8 ways
*/

#include <bits/stdc++.h>

using namespace std;

int n;
int m;
vector<int> arr;

int main(){
    cin >> n >> m;
    vector<int> count;

    //create arr, and initialize the count array
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
        count.push_back(0);
    }
    count.push_back(0);
    
    //get the count of each weights
    for (int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    int res = 0;
    //for each count of the same weight * rest of the count
    for (int i = 0; i < m; i++){
        n -= count[i];
        res += count[i] * n;
    }

    cout << res << '\n';
}