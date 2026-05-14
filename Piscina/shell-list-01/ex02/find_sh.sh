#!/bin/bash
# Procura no diretório atual e em todas as subpastas por arquivos que terminam
# com ".sh" e exibe apenas seus nomes, removendo o caminho e a extensão ".sh".
find . -type f -name "*.sh" -exec basename {} .sh \;
