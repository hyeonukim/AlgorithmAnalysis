/*
Question:
    you get a string s that's made up with number 0-9, from left to right, create a biggest number by using '+' or '*'
    between each character. All the operation starts from left to right

EX) 02984
    ((((0+2)*9)*8)*4) = 576
*/

#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    cin >> s;

    //convert first character to int
    int res = s[0] - '0';

    for (int i = 1; i < s.size(); i++){
        //convert the character to int
        int num = s[i] - '0';

        //if num is less or equal to 1, or the first character is 0 then add the num
        if (num <= 1 || res == 0){
            res += num;
        }
        //else multiply the num
        else{
            res *= num;
        }
    }

    cout << res << '\n';
}