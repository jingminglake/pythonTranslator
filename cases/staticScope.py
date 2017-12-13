x = 5
def f():
  print x
x = 100
def h():
  x = 10
  f()
h()
