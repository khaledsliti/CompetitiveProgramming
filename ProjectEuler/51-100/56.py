def count(num):
  res = 0
  while(num > 0):
    res += num % 10
    num = num // 10
  return res

ans = 0
for a in range(1, 100):
  for b in range(1, 100):
    ans = max(ans, count(a**b))
print(ans)