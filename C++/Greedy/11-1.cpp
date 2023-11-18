/*
Question:
    In a vaillage, there are N adventurers. In this adventure guild, they measured level of 'fear' for N adventurers.
    the higher level the 'fear' is, they perfrom less in dangerous situation. The guild master Dongbin tries to make
    a group as safe/efficient as possible by "If a member's level of 'fear' is X then there must be more or equal to 
    X people in the group for the adventure. Dongbin is curious how many groups he can make with the members.
    Create a code for Dongbin given N amount of people and information about them, that calculates how many total groups
    are possible.

EX)
    If N = 5, with each of their level of 'fear' being '2 3 1 2 2'
    then 
    Group 1: 1,2,3 Group 2: 2,2
    OR
    Group 1: 1, Group 2: 2,2 since we can always leave 2,3 in village
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

    //sort the array so we can get the smallest possible groups first
    sort(arr.begin(), arr.end());

    int count = 0;
    int res = 0;

    //for every element in array, increment the count, then per group that we get increase the group count
    for (int i = 0; i < n; i++){
        count += 1;
        if (count >= arr[i]){
            res += 1;
            count = 0;
        }
    }    
    cout << res << '\n';
}