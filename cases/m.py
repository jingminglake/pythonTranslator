def f(x,y):
  print x
  def g():
    print 1
    print x
    return 3
  return g
print f(1,2)()

