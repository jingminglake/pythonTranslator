def f(x):
  if x > 10:
    return
  else:
    x += 2
    print x
    f(x)
f(1)
