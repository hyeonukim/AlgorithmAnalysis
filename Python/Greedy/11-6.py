'''
Question from: https://school.programmers.co.kr/learn/courses/30/lessons/42891?language=python3
'''
import heapq

def solution(food_times, k):
    #if total food_time is smaller than k, return -1
    if (food_times) <= k:
        return -1
    
    # use priority queue so we can get rid of the food with least time
    q = []
    for i in range(len(food_times)):
        # push how long each food takes to eat, and food number
        heapq.heappush(q, (food_times[i], i+1))

    sum_val = 0 # how long it takes to eat
    prev = 0    # how long it took to eat previous food
    length = len(food_times) # number of food left

    # sum_val + (curr food time - previous food time) * number of food left
    while sum_val + ((q[0][0] - prev) * length) <= k:
        curr = heapq.heappop(q)[0]
        sum_val += (curr - prev) * length
        length -= 1 #remove the food that's done
        prev = curr 
        
    #check what food we're on
    res = sorted(q, key=lambda x: x[1])
    return res[(k-sum_val) % length][1]