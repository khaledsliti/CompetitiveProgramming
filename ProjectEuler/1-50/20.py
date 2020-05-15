fact = 1
for i in range(2, 101):
  fact = fact * i

ans = 0
for x in str(fact):
  ans = ans + int(x)

print(ans)
