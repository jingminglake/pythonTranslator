def wrapper():
  x=10
  def a(ab):
    ab-=1
    print ab
  a(x)
  print x

wrapper()
