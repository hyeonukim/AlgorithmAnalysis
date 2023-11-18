'''
Question:
    you get a string s that's made up with number 0-9, from left to right, create a biggest number by using '+' or '*'
    between each character. All the operation starts from left to right

EX) 02984
    ((((0+2)*9)*8)*4) = 576
'''

s = input()

res = int(s[0])

for i in range(1,len(s)):
    num = int(s[i])
    if res == 0 or num <= 1:     #if res = 0 or s[i] = 1, then we add since we want the biggest res
        res += num   
    else:                        #else, we multiply the number
        res *= num

print(res)