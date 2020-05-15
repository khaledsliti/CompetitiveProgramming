ans = 1
for i in range(1, 41):
  ans = ans * i
for i in range(1, 21):
  ans = ans // (i * i)
print(ans)
