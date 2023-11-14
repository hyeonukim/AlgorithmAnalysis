#Goal: to minimize the count of operations while making N to 1
#1. N = reduce N by 1
#2. N = divide N by k (only when N is divisible by k)

n, k = map(int, input("n, k: ").split())

count = 0

#when n is bigger than k, we want to divide as much as possible
while n >= k:
    while n % k != 0:
        n -= 1
        count += 1
    n //= k
    count += 1

#since we are adding operation every decrement of n, count += (n-1)
count += (n-1)

print(count)