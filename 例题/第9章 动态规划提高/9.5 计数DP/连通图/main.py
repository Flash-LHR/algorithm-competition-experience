M = 50

c = []
c.append([1])
for i in range(1, M + 1):
    c.append([1])
    for j in range(1, i):
        c[-1].append(c[-2][j - 1] + c[-2][j])
    c[-1].append(1)

f = []
f.append(1)
for i in range(1, M + 1):
    f.append(1<<((i*(i-1))//2))
    for j in range(1, i):
        f[-1] -= f[j] * c[i - 1][j - 1] * (1<<((i-j)*(i-j-1)//2))

while True:
    n = int(input())
    if n == 0:
        break
    print(f[n])