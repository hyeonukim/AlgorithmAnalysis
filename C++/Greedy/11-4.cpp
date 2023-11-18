/*
A store owner has N coins. Write a code that gets the smallest amount of money that isn't achievable with N coins.

EX)
    N = 5, each coin = 3,2,1,1,9
    1 - possible (1)
    2 - possible (1,1)
    3 - possible (3)
    4 - possible (2,1,1)
    5 - possible (3,2)
    6 - possible (3,2,1)
    7 - possible (3,2,1,1)
    8 - impossible - therefore, res = 8
*/

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

int main(){
    cin >> n;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int target = 1;
    //sort the array so we can start from the smallest number possible
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++){
        //if target is smaller than arr[i] then number is hard to achieve, therefore break
        if (target < arr[i]){
            break;
        }
        target += arr[i];
    }

    cout << target << '\n';
}