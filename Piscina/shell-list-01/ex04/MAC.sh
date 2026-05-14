#!/bin/bash
# Exibe todas as interfaces de rede, filtra as linhas que contêm endereços MAC
# (identificados pela palavra "ether") e imprime apenas o campo correspondente
# ao endereço MAC, exibindo um endereço por linha.
ifconfig | grep ether | awk '{print $2}'