val = 2 ** 1000
ans = 0
while val > 0:
  ans = ans + val % 10
  val = val // 10
print(ans)