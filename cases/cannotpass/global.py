def f():
    global x
    print x
    return

def g():
    x=10
    f()
    return
x=7
g()

def f():
    global x
    x+=1
    print x
    return

