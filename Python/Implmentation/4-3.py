#check how many ways knights can go
#EX) input: a1 output: 2, since it can only go to c2 or b3

input_data = input()
row = int(input_data[1])
col = int(ord(input_data[0])-int(ord('a'))+1)

dx = [1,-1,2,2,1,-1,-2,-2]
dy = [2,2,1,-1,-2,-2,1,-1]

res = 0
for i in range(8):
    if (8 >= row+dx[i] >= 1 and 8 >= col+dy[i] >= 1):
        res += 1

print(res)