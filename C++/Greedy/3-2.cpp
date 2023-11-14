/*
Time complexity:   O(1) if we don't count the sorting 
Space copmlexity:  O(1) if we don't count the sorting

N: Number of elements in list
M: Total number of times numbers should be added to make the biggest number
K: Maximum amount of one number can be added consecutively

EX) M = 8  K = 3  list = (2,4,5,4,6)  ans = 6+6+6+5+6+6+6+5 = 46
*/

#include <bits/stdc++.h>

using namespace std;

int n,m,k;
vector<int> v;

int main(){
    //retrieve N,M,K value from user
    cin >> n >> m >> k;

    //retrieve number list from user
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    // First sort the list to get the biggest number and second biggest number
    sort(v.begin(), v.end());

    int first_num = v[n-1];
    int second_num = v[n-2];

    /* 
    We can formulate the question as below:
    To get the biggest result, we must add as much of biggest number we can, and to do so we can only do it consecutively k times
    therefore, first_num * k + second_num (since second_num needs to be the 'refresher' to initialize the k to 0)
    we can do this (m // (k+1)) times, then the rest, we add first_num by (m % (k+1)) times.
    */
    int result = ((first_num * k + second_num) * (m / (k+1))) + ((first_num * (m % (k+1))));
    cout << result << '\n';

}