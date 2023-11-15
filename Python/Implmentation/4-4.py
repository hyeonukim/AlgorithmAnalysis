#Input: 
#   N * M map
#   x, y, dir   coordinate of the player, direction player is facing (0 = North, 1 = East, 2 = South, 3 = West)
#   1, 0 filled with N * M map where 1 = sea, 0 = land

#Output:
#   How many land did player get to touch/move to

#Rules:
#   1. Check if Left of player's direction is viable
#   2. If player hasn't been to, move to, Otherwise rotate only
#   3. If player has been to all 4 directions or been not able to go to go back 1. If player can not move back then return

n, m = map(int, input().split())

#a map to check if player has been to or not
d = [[0] * m for _ in range(n)]

x, y, direction = map(int, input().split())
d[x][y] = 1

#map for the game
array = []
for i in range(n):
    array.append(list(map(int, input().split())))

#NORTH, EAST, SOUTH, WEST
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

#turning left 
def turn_left():
    global direction
    direction -= 1
    if direction == -1:
        direction = 3

#counts how many lands we moved to
#turn time = how many times player turned
count = 1
turn_time = 0

while True:
    #step 1
    turn_left()

    nx = x + dx[direction]
    ny = y + dy[direction]

    #step 2
    if d[nx][ny] == 0 and array[nx][ny] == 0:
        d[nx][ny] = 1
        x = nx
        y = ny
        count += 1
        turn_time = 0
        continue

    else:
        turn_time += 1
    
    #step 3
    if turn_time == 4:
        nx = x-dx[direction]
        ny = y-dy[direction]

        if array[nx][ny] == 0:
            x = nx
            y = ny
        else:
            break
        turn_time = 0
    
print(count)





