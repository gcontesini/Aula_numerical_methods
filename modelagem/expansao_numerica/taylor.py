import numpy

a=raw_input("Menu:\n1-Exponencial\n2-Logaritmo\n3-Polinomial\n4-\n9-Sair:\n")
funcao=input("Digite a funcao:")
f=numpy.poly1d(funcao)
def f(x):
	print f(x)
	return f(x)

def df(x,fun,o):
	for i in range(o):
		dfun = fun.deriv()
		print dfun(x)
		return dfun(x)
		fun=dfun

def fat(x):
	fat=1
	for i in range(x):
		fat=fat*i
	print fat
	return fat

def taylor(cen,fx):
	tay=0
	for i in range(int(1e3)):
		tay=tay+(df(cen,funcao,i)*(x-cen)/fat(i))
	print tay

print taylor(0,f)
