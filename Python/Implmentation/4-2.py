#Write a program that takes an input N which results in N:00:00 to N:59:59
#that counts up all the times that includes 3 in any of the time
#EX) 0:00:03 count += 1, 0:13:00 count += 1

n = int(input())

count = 0
for i in range(n+1):
    for j in range(60):
        for z in range(60):
            if ('3' in str(i)+str(j)+str(z)):
                count += 1

print(count)