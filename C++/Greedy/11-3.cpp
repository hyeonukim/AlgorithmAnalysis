/*
Question:
    Rick has a string s that's contained with 0s and 1s. Rick is trying to make all the numbers in s the same.
    What Rick can do is to flip the numbers, meaning 1 becomes 0, and vice versa. Create a code that returns number of least flips possible
    For example if s = 0001100
        1. Flipping whole becomes 1110011
        2. Flipping from 4th character to 5th would end with 11111111
    
EX) 0001100
    Rick only needs to flip once from 4th character to 5th
    res = 1    
*/

#include <bits/stdc++.h>

using namespace std;

string s;

int main(){

    cin >> s;

    int zeros = 0;
    int ones = 0;

    //if previous character is different from the next one, then increment the count of zero/one
    for (int i = 0; i < s.size()-1; i++){
        char prev = s[i];
        if (prev != s[i+1]){
            if (prev == '0'){
                zeros += 1;
            }
            else{
                ones += 1;
            }
        }
    }
    
    //increment the count of the very last character
    if (s[s.size()-1] == '0') zeros++;
    else ones++;

    cout << min(zeros, ones) << '\n';

}