def f():
  x=7
  def g(y):
    if y == 0:
      return 0
    return g(-1)
  print g(5)

print f()
     
