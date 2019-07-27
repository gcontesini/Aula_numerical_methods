# -*- coding: utf-8 -*-
#################################################################################
#                                                                               #
#                                   Game.py                                     #
#                                                                               #
#################################################################################
#                                                                               #
#   Esse arquivo contem as definicoes da classe Game.                           #
#                                                                               #
#################################################################################

import random
import pygame
import time
import math

from log import *
from cell import *
from colors import *
from button import *

class Game:
    border_color = black
    border_thickness = 5
    color = gray
    cell_margin = 5
    cell_count_horizontal = 20
    cell_count_vertical = 12
    cell_width = 60
    cell_height = 60
    delay = 150
    
    path = []

    # Inicializa a classe
    #
    # @in window: janela na qual esta celula pertence
    # @in log: gerenciador de estados
    # @in width: largura do tabuleiro
    # @in height: altura do tabuleiro
    def __init__(self, window, log, width, height):
        self.window = window
        self.log = log
        self.height = height
        self.width = width
        self.cells = [] # inicializa a matriz de celulas
        self.last = 0 # momento em que a ultima atualizacao de "posicao" foi feita.
        self.text = "" # texto que vai fazer um overlay em toda a tela
        random.seed() # inicializa a semente dos numeros pseudo-randomicos com o tempo atual.
        self.create()

    # Cria todas as celulas e as organiza na matriz.
    def create(self):
        left = 0
        top = 0
        id = 1
        for i in range(self.cell_count_vertical):
            row = []
            self.cells.append(row)
            for j in range(self.cell_count_horizontal):
                cell = Cell(self.window, id, pygame.Rect(left, top, self.cell_width, self.cell_height), i, j)

                left += self.cell_width + self.cell_margin
                row.append(cell)
                id += 1
                
            top += self.cell_height + self.cell_margin
            left = 0

    # Ajusta a ponto para o local onde as celulas comecam a ser pintadas e verifica se o ponto esta sobre alguma celula.
    #
    # @in pos: vetor com a coordenada x e y, ajustada para o posicionamento local do tabuleiro.
    # @out: A celula sobre o ponto ou None.
    def getCellByPosition(self, pos):
        pos[0] -= self.border_thickness + (self.width - ((self.cell_width + self.cell_margin) * self.cell_count_horizontal))/2
        pos[1] -= self.border_thickness + (self.height - ((self.cell_height + self.cell_margin) * self.cell_count_vertical))/2
        for i in range(len(self.cells)):
            for j in range(len(self.cells[i])):
                if self.cells[i][j].rect.collidepoint(pos):
                    return self.cells[i][j]

        return None
        
    # Identifica uma celula através de seu id.
    #
    # @in id: id da célula.
    # @out: A célula procurada ou None.
    def getCellById(self, id):
        for i in range(len(self.cells)):
            for j in range(len(self.cells[i])):
                if self.cells[i][j].id == id:
                    return self.cells[i][j]

        return None

    # Pinta o tabuleiro e suas celulas
    #
    # @in rect: rect da regiao para ser pintada, com as coordenadas left e top ajustadas para o posicionamento local do tabuleiro.
    def paint(self, rect):
        # Primeiro pintamos todo o tabuleiro e depois pintamos por cima a borda deste.
        pygame.draw.rect(self.window, self.color, rect)
        pygame.draw.rect(self.window, self.border_color, rect, self.border_thickness)

        # Ajustamos as coordenadas left e top para o ponto onde as celulas comecam a ser pintadas
        rect.left += self.border_thickness + (self.width - ((self.cell_width + self.cell_margin) * self.cell_count_horizontal))/2
        rect.top += self.border_thickness + (self.height - ((self.cell_height + self.cell_margin) * self.cell_count_vertical))/2
        for i in range(len(self.cells)):
            for j in range(len(self.cells[i])):
                self.cells[i][j].paint(rect)
                
        # Pintamos o texto overlay
        font = pygame.font.Font(None, 40)
        text = font.render(self.text, True, white)
        self.window.blit(text, [self.width/2 - 160, self.height/2 - 345])

    # Atualizamos a cor da celula.
    #
    # @in cell: celula para ser alterada
    def updateCell(self, cell):
        if cell.color == blue:
            self.log.update("Atualiza " + str(cell.id) + " Blue -> Gray")
            cell.color = gray
        elif cell.color == gray:
            self.log.update("Atualiza " + str(cell.id) + " Gray -> Yellow")
            cell.color = yellow
        elif cell.color == yellow:
            self.log.update("Atualiza " + str(cell.id) + " Yellow -> Black")
            cell.color = black
        elif cell.color == black:
            self.log.update("Atualiza " + str(cell.id) + " Black -> Blue")
            cell.color = blue

    # Calcula a distancia entre duas celulas atraves do método Manhattan
    def getManhattanDistance(self, cellA, cellB):
        return math.fabs(cellA.index_x - cellB.index_x) + math.fabs(cellA.index_y - cellB.index_y)
        
    # Reinicia o valor das celulas.
    def clear(self):
        self.log.update("Limpa a malha")
        for i in range(len(self.cells)):
            for j in range(len(self.cells[i])):
                self.cells[i][j].color = blue
               
        self.text = ""
        for i in self.path:
            self.path.remove(i)

    # Inicia a busca pela melhor trajetoria.
    def start(self):
        self.log.update("Calcula caminho")
        
        start = None
        goal = None
        
        # Verificacoes iniciais
        for i in range(len(self.cells)):
            for j in range(len(self.cells[i])):
                if self.cells[i][j].color == gray:
                    if start != None:
                        self.log.update("Utilize apenas um cinza (inicio)")
                        return
                        
                    start = self.cells[i][j]
                    
                elif self.cells[i][j].color == yellow:
                    if goal != None:
                        self.log.update("Utilize apenas um amarelo (final)")
                        return
                        
                    goal = self.cells[i][j]
        
        if start == None or goal == None:
            self.log.update("Voce deve definir um inicio e fim.")
            return
            
        # Limpa trajetorias recentes
        for i in range(len(self.cells)):
            for j in range(len(self.cells[i])):
                if self.cells[i][j].color == red:
                    self.cells[i][j].color = blue

        # Inicia as duas listas principais para o algoritmo
        closedset = []
        openset = []
                
        # Adiciona o ponto inicial na lista de possiveis caminhos
        openset.append(start)
        
        # Enquanto houver algum caminho possivel
        while len(openset) > 0:
            current = None
            for cell in openset: # Busca o menor caminho dentre os possiveis
                if current == None or cell.cost < current.cost or (cell.cost == current.cost and random.randint(0, 1) == 0):
                    current = cell
            
            # Remove esta celular da lista de possibilidades e adiciona ela na lista de celulas ja verificadas
            closedset.append(current)
            openset.remove(current)
            if current == goal: # Verifica se este e a celula final
                break

            # Realiza uma busca nas celulas adjacentes
            for i in [0, 1]:
                for j in [-1, 1]:
                    x = current.index_x - j*i
                    y = current.index_y - j*(1 - i)
                    
                    # Verifica se esta possivel celula adjacente esta fora dos limites do tabuleiro
                    if x == -1 or y == -1 or x == self.cell_count_horizontal or y == self.cell_count_vertical:
                        continue
            
                    neighbor = self.cells[y][x]
                    if neighbor.color == black: # Se for da cor preta, nao e possivel passar
                        closedset.append(neighbor)

                    if neighbor in closedset: # Se esta na lista de celulas ja verificadas, ignorar
                        continue

                    if neighbor in openset: # Se ja esta na lista de caminhos possiveis
                        if current.cost_g + 1.0 < neighbor.cost_g: # Verifica se este e um caminho melhor, se for substitua os custos
                            neighbor.parent = current
                        
                            neighbor.cost_g = current.cost_g + 1.0
                            neighbor.cost_h = self.getManhattanDistance(neighbor, goal)
                            neighbor.cost = neighbor.cost_g + neighbor.cost_h
                    else: # Adiciona a celula a lista de possibilidade e adiciona os seus custos
                        openset.append(neighbor)
                        neighbor.parent = current # Adiciona a celula adjacente uma referencia a esta celula como sua responsavel, ou 'pai'
                        
                        neighbor.cost_g = current.cost_g + 1.0
                        neighbor.cost_h = self.getManhattanDistance(neighbor, goal)
                        neighbor.cost = neighbor.cost_g + neighbor.cost_h

        # Partindo do ponto inicial, trace a rota atraves das celulas 'pai' de cada uma
        current = goal.parent
        if current: # Caso exista algum caminho possivel
            while current != start:
                self.path.append(current)
                current = current.parent
                
            # A trajetoria e o caminho reverso a este definido
            self.path.reverse()

    # Funcao que roda o tempo todo para determinar os eventos.
    def update(self):
        millis = int(round(time.time() * 1000)) # Obtem o tempo em milisegundos.
        if millis - self.last > self.delay: # Verifica quanto tempo se passou desde a ultima atualizacao.
            if len(self.path) > 0:
                self.path[0].color = red
                self.path.remove(self.path[0])
                
                # Determina que houve uma atualizacao, assim tera um intervalo ate a proxima.
                self.last = millis
