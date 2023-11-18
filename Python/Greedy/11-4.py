'''
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
'''

n = int(input())
coins = list(map(int, input().split()))
coins.sort()

target = 1
for x in coins:
    if target < x:
        break
    target += x

print(target)
