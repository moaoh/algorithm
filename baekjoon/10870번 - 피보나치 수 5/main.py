t = [0] * 21

def pivo(n):
	if n == 0:
		return 0
	if n == 1:
		return 1
	if t[n]:
		return t[n]
	return pivo(n - 1) + pivo(n - 2)

n = int(input())

print(pivo(n))