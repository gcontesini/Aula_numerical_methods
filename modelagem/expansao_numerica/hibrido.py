# -*- coding:utf-8 -*-		#Codigo para reconhecer a acentuação latina
from math import * 		#Biblioteca para funcoes matematicas
from random import random	#Biblioteca de funções pseudo-randomicas
from numpy import *		#Biblioteca numpy
import os			#Biblioteca que escreve comandos no terminal
import sys			#Biblioteca da função sys.argv



#	constantes de interacao

time=sys.argv[3]	#tempo de duracao da simulacao
time=int(time)		#conversao de string para int
dt=1			#variacao infinitesimal do tempo

#	particulas

v=0.25			#velocidade inicial
global p		#variavel global
p=sys.argv[1]		#numero de particulas
p=int(p)		#conversao de string para int


#constantes do solido



#	Dimensao

global dim
dim=sys.argv[2]		#dimensao do solido
dim=float(dim)		#conversao de string para float

#	coordenadas e velocidade das particulas

x=array([])
y=array([])
z=array([])

vx=array([])
vy=array([])
vz=array([])

#funções

	#Condições de contorno

def cond_contor():
	if x[i]>=dim:
		vx[i]=vx[i]*(-1)
		return vx[i]
	if x[i]<=0.00:
		vx[i]=vx[i]*(-1)
		return vx[i]
	if y[i]>=dim:
		vy[i]=vy[i]*(-1)
		return vy[i]
	if y[i]<=0.00:
		vy[i]=vy[i]*(-1)
		return vy[i]
	if z[i]>=dim:
		vz[i]=vz[i]*(-1)
		return vz[i]
	if z[i]<=0.00:
		vz[i]=vz[i]*(-1)
		return vz[i]

	#atualização da posição

def atu_pos():
	x[i]=x[i]+vx[i]*dt
	y[i]=y[i]+vy[i]*dt
	z[i]=z[i]+vz[i]*dt

	#colisao

#def test_colisao(x):
#	for x[i] in x[1:]:
#		if x[i] == x[1:]:
#			print "e pause 0.2"
#			print "splot '-' w p lw 4 linecolor rgb 'green'"
#			print x[i] ,"\t", y[i] , "\t" , z[i]
#			print "e pause 0.2"

##################################################
##		Simulção			##
##################################################

#	calculos iniciais

for i in range(p):

	#posição inicial

	x=append(x,[0.1])
	y=append(y,[0.1])
	z=append(z,[0.1])

	#velocidade

	vx=append(vx,[v*random.random()])
	vy=append(vy,[v*random.random()])
	vz=append(vz,[v*random.random()])

#	inicializacao do grafico

#print "set xrange [0:10]"
#print "set yrange [0:10]"
#print "set zrange [0:10]"
#print "splot '-' w p lw 3 linecolor rgb 'blue'"

#	interacao das particulas

for j in range(0,time):
	for i in range(p):
		atu_pos()

	#############################
	#	condicoes de contorno
	#############################

		cond_contor()

	############################
	#	dados
	############################

		print x[i] ,"\t", y[i] , "\t" , z[i]

	############################
	#	Condições de Colisao
	############################

	#		test_colisao(x)
	#		test_colisao(y)
	#		test_colisao(z)

	############################
	#	filme 
	############################

#	print "e pause 0.1"
#	print "set xrange [0:10]"
#	print "set yrange [0:10]"
#	print "set zrange [0:10]"
#	print "splot '-' w p lw 3 linecolor rgb 'blue'"
	
#para rodar digite python prog.py | gnuplot

