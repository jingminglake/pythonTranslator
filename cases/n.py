#x = 1
#def h():
#  print x
#  x = 2
#h()
def f(x,y):
    print x
    print y
    return f
f(1,2)(3,4)

def g(x):
    print x
    return g
g(1)(2)(3)(4)(5)(6)(7)

def g(x):
    print x
    f(x,x)
    return g
g(1)

