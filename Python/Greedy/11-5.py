'''
A, B each are playing bowling. They are trying to choose different weight of bowling bowl from each other.
There are total N bowling balls. Each weighing from range of 1-M kg. There may be some balls that weight the same.
Write a code that calculates how many combinations A,B can have

EX) N = 5, M = 3, arr = 1,3,2,3,2

ans = (1,3), (1,2), (1,3), (1,2), (3,2), (3,2), (2,3), (3,2) - therefore there are 8 ways
'''
n, m = map(int, input().split())

weights = list(map(int, input().split()))

res = 0
arr = [0] * (m+1)

#hash table to get the counts of each weights
for x in weights:
    arr[x] += 1

for i in range(1, m+1):
    n -= arr[i]         #for that weight count * rest of the count
    res += arr[i]*n

print(res)