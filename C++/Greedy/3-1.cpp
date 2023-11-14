//Time complexity:   O(K) where K represents the number of types of coin/bill
//Space complexity:  O(1)

#include <iostream>

using namespace std;

// n:            how much money customer wants
// cnt:        how much bill customer gets
int n = 1260;
int cnt = 0;

// coin_types:   how much each coin/bill customer can get
// note that we start from highest coin/bill type (500 >> 100 >> 50 >> 10)
int coin_types[4] = {500, 100, 50, 10};

int main() {
    for (int i = 0; i <= 4; i++){
        int coin = coin_types[i];
        cnt += n / coin;
        n %= coin;
    }

    cout << cnt << '\n';
}