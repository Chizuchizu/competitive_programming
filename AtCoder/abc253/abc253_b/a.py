h, w = map(int, input().split())

S = []

d = []

for i in range(h):
    s = input()
    S.append(s)
    for j, c in enumerate(s):
        if c == "o":
            d.append(
                    [i, j]
                    )




ans = abs(d[0][0] - d[1][0]) + abs(d[0][1] - d[1][1])
print(ans)
