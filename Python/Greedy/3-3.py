#Time Complexity: O(n*m)
#Space Complexity:O(1)

# Goal: to get the highest number of the smallest among each rows
# N = number of rows
# M = number of cols
# 1. First select the row number
# 2. Select the lowest number among that row
# 3. Ultimately you want the highest number amongst the row of the cards
# EX) 3 1 2
#     4 1 4     Here, 2 is the output as 2 is the highest number amongst the lowest of each rows (1, 1, 2)
#     2 2 2

n, m = map(int, input("n, m: ").split())

result = 0

#for each row, get the min value
#if there is a bigger value, then replace the result value
for i in range(n):
    data = list(map(int, input().split()))
    min_val = min(data)
    result = max(result, min_val)
    
print(result)