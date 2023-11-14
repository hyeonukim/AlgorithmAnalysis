#Time complexity:   O(1) if we don't count the sorting 
#Space copmlexity:  O(1) if we don't count the sorting

# N: Number of elements in list
# M: Total number of times numbers should be added to make the biggest number
# K: Maximum amount of one number can be added consecutively

# EX) M = 8  K = 3  list = (2,4,5,4,6)  ans = 6+6+6+5+6+6+6+5 = 46

#retrieve N,M,K value from user
n,m,k = map(int, input("n, m, k: ").split())

#retrieve number list from user
data = list(map(int, input("list of elements: ").split()))

# First sort the list to get the biggest number and second biggest number
data.sort()

first_num = data[n-1]
second_num = data[n-2]

# We can formulate the question as below:
# To get the biggest result, we must add as much of biggest number we can, and to do so we can only do it consecutively k times
# therefore, first_num * k + second_num (since second_num needs to be the 'refresher' to initialize the k to 0)
# we can do this (m // (k+1)) times, then the rest, we add first_num by (m % (k+1)) times.
res = ((first_num * k + second_num) * (m // (k+1))) + (first_num * (m % (k+1)))

print(res)