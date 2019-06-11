# inventario

É preciso ter o Docker instalado para fazer o build do programa dentro do Container.

## Cria a imagem e compila o código
docker build -t debian-lenny .

## Sobe um container com o código já compilado
docker run --name lenny --rm -it debian-lenny bash

## Copia o binário de dentro do container para o diretório local
docker cp lenny:/code/bin/inventario-TH .
