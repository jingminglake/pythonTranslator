if False:
    print 1
else:
    print 2


if False: 
    print 1
elif True:
    print 2
else:
    print 3

if False:
    if True:
        print True
    else:
        print False
elif True:
    if False:
        print False
    else:
        print True
else:
    print True


def f(x):
    print "in f"
    if x :
        return 3
    else :
        return 4

print f(True)
print f(False)

def f():
    print 1
f()

def f(x):
    print x
    if x > 1:
        return x * f(x-1)
    else:
        return 1

print f(5)
print f(12)

def f(x):
    print x
    if x > 1:
        return f(x-1) * f(x-1)
    else:
        return 1

print f(5)
