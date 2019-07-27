# -*- coding:utf-8 -*-	#Codigo para reconhecer a acentuação latina
from math import * 	#biblioteca para funcoes matematicas
import os		#biblioteca que escreve comandos no terminal
import sys

#	escolha do solidos
#		Improvisação do switch() em python

#	Definir as funções para o "switch"

#	Cubo
def case_1():
	global m
	global n
	global o
	global p
	n=int(raw_input("Digite o lado do Cubo:"))
	p=int(raw_input("Digite o numero de particulas:"))
	m=n
	o=n
	os.system("python prog.py args.py "+str(m)+str(n)+str(o)+str(p)+"| gnuplot")
#	Esfera
def case_2():
	int(raw_input("Digite o raio da esfera:"))
	n=sqrt(pow(r)-pow(m)-pow(o))
	m=sqrt(pow(r)-pow(n)-pow(o))
	o=sqrt(pow(r)-pow(m)-pow(n))
	os.system("python prog.py args.py "+str(m)+str(n)+str(o)+"| gnuplot")
#	Sair
def case_3():
	a=0
def case_default():
    print 'Numero inválido'

#cria um dicionário que relaciona cada função com a opção desejada

dict = {1 : case_1, 2 : case_2, 3 : case_3}


def switch(a):
	try:
		dict[a]()
	except:
		case_default()
try:
	switch(input("Solidos:\n1-Cubo\n2-Esfera\n3-Sair\nDigite o solido que deseja para a simulação:"))
except:
	print '**_Erro-42_**Numero invalido!'


