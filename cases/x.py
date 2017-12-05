x = y = 151
def f():
  y = 100
  def g():
    print x
    print y
  g()
f()
print y
