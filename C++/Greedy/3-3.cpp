/*
Time Complexity: O(n*m)
Space Complexity:O(1)

Goal: to get the highest number of the smallest among each rows
N = number of rows
M = number of cols
1. First select the row number
2. Select the lowest number among that row
3. Ultimately you want the highest number amongst the row of the cards
EX) 3 1 2
    4 1 4     Here, 2 is the output as 2 is the highest number amongst the lowest of each rows (1, 1, 2)
    2 2 2

NOTE THAT SOLUTION IS DIFFERENT FROM PYTHON VERSION
this uses 2 for loops
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
int res;

int main(){
    cin >> n >> m ;

    //for each element, we get the smallest number in row
    //then compare the smallest number of the row with res to get the highest num
    for (int i = 0; i < n; i++){
        //any big value is ok
        int min_val = 10001;
        for (int j = 0; j < m; j++){
            int x;
            cin >> x;
            min_val = min(min_val, x);
        }
        res = max(res, min_val);
    }

    cout << '\n' << res << '\n';
}