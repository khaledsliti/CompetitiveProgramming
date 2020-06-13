def reverse(num):
  res = 0
  while num > 0:
    res = res * 10 + num % 10
    num = num // 10
  return res

def check(num):
  for _ in range(0, 55):
    num += reverse(num)
    # print(num)
    if(num == reverse(num)):
      return True
  return False

ans = 0
for num in range(0, 10001):
  if not check(num):
      ans += 1

print(ans)