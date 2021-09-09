n = int(input())
t = int(input())

com = [[0 for i in range(n + 1)] for j in range(n + 1)] 
check = [0] * (n + 1)
num = 0

for _ in range(t):
	x, y = map(int, input().split())
	com[x][y] = 1
	com[y][x] = 1

def dfs(c):
	check[c] = 1
	for x in range(n + 1):
		if com[c][x] == 1 and check[x] == 0:
			dfs(x)

dfs(1)

print(check.count(1) - 1)
