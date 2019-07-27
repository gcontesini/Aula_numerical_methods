# -*- coding:utf-8 -*-	#Codigo para reconhecer a acentuação latina
from math import * 	#biblioteca para funcoes matematicas
from random import *
from numpy import *
import os		#biblioteca que escreve comandos no terminal
import sys

#	constantes de interacao

temp=10000		#tempo de duracao da simulacao
dt=1			#variacao infinitesimal do tempo
##escolha entre esfera cilindro piramide paralelograma

#	constantes fisicas

v=0.1			#velocidade inicial
k=1			#constante de atrito
g=9.8			#gravidade

#	particulas

global p
p=1

#	constantes do solido
global m
global n
global o
m=10
n=m
o=m
type(m)
#	coordenadas e velocidade das particulas

x=array([])
y=array([])
z=array([])

vx=array([])
vy=array([])
vz=array([])

	#funções
#atualização da posição
def atu_pos(pos,velo,delt):
	pos=pos+velo*delt
#colisao
def test_colisao(x):
	for x[i] in x[1:]:
		if x[i] == x[1:]:
			print "e pause 0.2"
			print "splot '-' w p lw 4 linecolor rgb 'green'"
			print x[i] ,"\t", y[i] , "\t" , z[i]
			print "e pause 0.2"

##################################################
##		Simulção			##
##################################################

#	calculos iniciais

for i in range(p):

	#posição inicial

	x=append(x,[1])
	y=append(y,[2])
	z=append(z,[3])

	#velocidade

	vx=append(vx,[v*sin(y[i]/x[i])])
	vy=append(vy,[v*cos(y[i]/x[i])])
	vz=append(vz,[v*sin(z[i]/x[i])])

#	inicializacao do grafico

print "splot '-' w p lw 4"

#	interacao das particulas

for j in range(0,temp):
	for i in range(0,p):
		atu_pos(x[i],vx[i],dt)
		atu_pos(y[i],vy[i],dt)
		atu_pos(z[i],vz[i],dt)

#############################
#	condicoes de contorno
#############################

		if x[i]>=m:
			vx[i]=vx[i]*(-1)
		if x[i]<=0.00:
			vx[i]=vx[i]*(-1)
		if y[i]>=n:
			vy[i]=vy[i]*(-1)
		if y[i]<=0.00:
			vy[i]=vy[i]*(-1)
		if z[i]>=o:
			vz[i]=vz[i]*(-1)
		if z[i]<=0.00:
			vz[i]=vz[i]*(-1)

############################
#	filme 
############################
		for i in range(0,p):
			print x[i] ,"\t", y[i] , "\t" , z[i]

############################
#	Condições de Colisao
############################

		test_colisao(x)
		test_colisao(y)
		test_colisao(z)

		print "e pause 0.2"
		print "splot '-' w p lw 2 "

#para rodar digite python progpy.py | gnuplot

