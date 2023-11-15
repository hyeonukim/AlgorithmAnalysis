#Goal: a user can input L(left) R(right) U(up) D(down)
#If user's input goes out of bounds of NxN space, then it should not move, Otherwise get the output of the final location
#EX) in a 5x5 space command is: R R R U D D
#then the final output should be '3 4' as (1,1)-(1,2)-(1,3)-(1,4)-(1,4)-(2,4)-(3,4)

n = int(input("n: "))

plans = input().split()

#each represents start x,y coordinate
x, y = 1, 1

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
move_types = ['L', 'R', 'U', 'D']

#for every move, we check the type of the move and move it temporary
#if our temporary move is valid (not out of bounds) then x, y = nx, ny
for move in plans:
    for i in range(len(move_types)):
        if move == move_types[i]:
            nx = x + dx[i]
            ny = y + dy[i]
    #checks for out of bounds
    if nx < 1 or ny < 1 or nx > n or ny > n:
        continue
    x, y = nx, ny

print(x, y)