# -*- coding:utf-8 -*-	#Codigo para reconhecer a acentuação latina
import os		#biblioteca que escreve comandos no terminal
import sys		#Biblioteca da função sys.argv

#	Definir as funções para o "switch"

#	Cubo

def case_1():
	try:
		global l
		l=int(raw_input("Digite o lado do Cubo(1-10):"))
		
	except(NameError,TypeError,EOFError,ValueError):
		print "\n\nErro na simulação!\nReinicie o script!\n\n "

#	Sair

def case_2():
	print "\t*GoodBye\n"

def case_default():
	print '\nNumero inválido'

#	cria um dicionário que relaciona cada função com a opção desejada

dict = {1 : case_1, 2 : case_2}

#	Improvisação do switch() em python

def switch(a):
	try:
		dict[a]()
	except:
		case_default()

#	escolha do solidos

try:
	switch(input("Opções:\n1-Cubo\n2-Sair\nEscolha a opção :"))
	global t
	global par
	try:
		t=int(raw_input("Digite o tempo de simulação:"))
		par=int(raw_input("Digite o numero de particulas:"))
	except(NameError,TypeError,EOFError,ValueError):
		print "\n\nErro na simulação!\nReinicie o script!\n\n "
except:
	print "\n\nErro na simulação!\nReinicie o script!\n\n "

#	output
os.system("python hibrido.py "+str(par)+"\t"+str(l)+"\t"+str(t)+"> data.dat")
