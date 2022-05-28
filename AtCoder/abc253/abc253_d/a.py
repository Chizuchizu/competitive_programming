from fractions import gcd
n, a, b = map(int, input().split())

sumn = (1 + n) * n // 2

lcm = a * b / gcd(a, b)
maxa = n // a
maxb = n // b
maxab = n // lcm


suma = (maxa * (2 * a + (maxa - 1) * a)) // 2
sumb = (maxb * (2 * b + (maxb - 1) * b)) // 2
sumab = (maxab * (2 * a * b + (maxab - 1) * lcm)) // 2

if a == b:
    print(sumn - suma)
elif b % a == 0:
    print(sumn - suma)
elif a % b == 0:
    print(sumn - sumb)
else:
    print(sumn - suma - sumb + sumab)
