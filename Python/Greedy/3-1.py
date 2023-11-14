#Time complexity:   O(K) where K represents the number of types of coin/bill
#Space complexity:  O(1)

# n:            how much money customer wants
# count:        how much bill customer gets
# coin_types:   how much each coin/bill customer can get
n = 1260
count = 0

# note that we start from highest coin/bill type (500 >> 100 >> 50 >> 10)
coin_types = [500, 100, 50, 10]

for coin in coin_types:
    count += n // coin
    n %= coin

print(count)