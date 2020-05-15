a = 1
b = 1

it = 2
while len(str(b)) < 1000:
  c = a + b
  a = b
  b = c
  it += 1

print(it)