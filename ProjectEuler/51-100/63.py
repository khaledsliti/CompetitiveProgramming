ans = 0
for N in range(1, 50):
  for a in range(1, 50):
    if len(str(a ** N)) == N:
      ans += 1
print(ans)