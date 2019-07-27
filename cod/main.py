# -*- coding: utf-8 -*-
#################################################################################
#                                                                               #
#                                   Main.py                                     #
#                                                                               #
#################################################################################
#                                                                               #
#   Esse arquivo contem o objeto da interface e coordena o loop principal.      #
#                                                                               #
#################################################################################

from interface import *

interface = Interface(1920, 1024, "Projeto Python - A*")

while True:
    if not interface.update():
        interface.onExit()
        sys.exit()
        break
