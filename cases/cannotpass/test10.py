def f(x):
  print("parameter x:", x)
  x=0
  print("f():",x)
  return x


def fplus(x):
  for k in x:
    k=k+1
    print(k)
  print(x)
  return x



x=10
f(x)
print x
print "aaaaaaaaaa"
print f(x)

print "bbbbbbbbbbbbb"
print 

z=[1,2,3]
fplus(z)
print (z)
print "ccc"
print fplus(z)



