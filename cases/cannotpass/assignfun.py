def h(x):
    print x
    def a(z):
        print z
    a(3)
h(2)
h(3)

a=h
a(4)

def f(x):
    z=35
    def y():
        c=z
        print c
    return y
f(2)
a=f(3)
a()
