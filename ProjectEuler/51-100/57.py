def calc(len):
  a = 1
  b = 2
  for _ in range(len - 1):
    a += 2 * b
    c = a
    a = b
    b = c
  return a + b, b

ans = 0
for i in range(1, 1001):
  a, b = calc(i)
  if(len(str(a)) > len(str(b))):
    ans += 1

print(ans)