#!/bin/bash
# Percorre o diretório atual (.) e todas as suas subpastas, selecionando tanto
# arquivos regulares (-type f) quanto diretórios (-type d), incluindo o próprio
# diretório inicial ".", e envia o resultado para o comando wc -l, que conta
# o número total de entradas encontradas.
find . \( -type f -o -type d \) | wc -l
