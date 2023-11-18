'''
Question:
    Rick has a string s that's contained with 0s and 1s. Rick is trying to make all the numbers in s the same.
    What Rick can do is to flip the numbers, meaning 1 becomes 0, and vice versa. Create a code that returns number of least flips possible
    For example if s = 0001100
        1. Flipping whole becomes 1110011
        2. Flipping from 4th character to 5th would end with 11111111
    
EX) 0001100
    Rick only needs to flip once from 4th character to 5th
    res = 1    
'''

s = input()

zeros = 0
ones = 0


for i in range(len(s)-1):
    prev = s[i]                 #prev = s[i]
    if prev != s[i+1]:          #check if prev is different to the next character
        if prev == '0':         #if it is 0, then add the count of 0
            zeros += 1
        else:                   #else, add the count of 1
            ones += 1

if s[len(s)-1] == '0':          #if the last character is 0, add the count of 0
    zeros += 1
else:                           #else, add the count of 1
    ones += 1                   

#return the min of count of 0, and 1
print(min(zeros, ones))          