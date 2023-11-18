'''
Question:
    In a vaillage, there are N adventurers. In this adventure guild, they measured level of 'fear' for N adventurers.
    the higher level the 'fear' is, they perfrom less in dangerous situation. The guild master Dongbin tries to make
    a group as safe/efficient as possible by "If a member's level of 'fear' is X then there must be more or equal to 
    X people in the group for the adventure. Dongbin is curious how many groups he can make with the members.
    Create a code for Dongbin given N amount of people and information about them, that calculates how many total groups
    are possible.

EX)
    If N = 5, with each of their level of 'fear' being '2 3 1 2 2'
    then 
    Group 1: 1,2,3 Group 2: 2,2
    OR
    Group 1: 1, Group 2: 2,2 since we can always leave 2,3 in village
'''

n = int(input())
fear = list(map(int, input().split()))
fear.sort()

#count refers to counting member in one group
#res refers to amount of groups
count = 0
res = 0

#starting from the lowest level of fear
for i in fear: 
    count += 1      #increase the count 
    if count >= i:  #if that count is equal or more than level of fear, then group is formed
        res += 1    #increase the group count
        count = 0   #reset the count to 0


print(res)