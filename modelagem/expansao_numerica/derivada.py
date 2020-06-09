import numpy

print "Ex: [3,1,2] = 3*x**2 + 1*x**1 + 2*x**0"
a=input("Digite a matriz de coeficientes:")

p = numpy.poly1d(a)

q = p.deriv()

print p,"\n",q,'\n'

n=100
b=-100

i=0
while i<=10:
	m=n-(p(n)/q(n))
	n=m
	print m-1
	if p(m-1)==0:
		print p(m-1)
		i=10
	i=i+1

i=0
while i<=10:
	a=b-(p(b)/q(b))
	b=a
	print a
	if p(a)==0:
		print p(a)
		i=10
	i=i+1

print a,"eh raiz"
print m-1,"eh raiz"

