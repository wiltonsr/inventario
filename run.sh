#!/bin/bash

/code/bin/inventario-TH \
  --db-host 10.123.40.150 \
  --db-user root \
  --db-passwd caixa \
  --db-database database-name \
  --db-so-table nome-so-table \
  --db-software-table nome-soft-table \
  --hostname nome-maquina \
  --tipo-equipamento tipo-equipamento \
  --endereco-ip endereco-ip \
  --sistema-operacional SO \
  --kernel 'kernel version' \
  --baixa-imagem data \
  --data-inventario '123232434' \
  --cmthin 'versao-cmthin' \
  --fabricante Diebold
