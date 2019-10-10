# binary-search-tree

![CI status](https://github.com/ThyagOliveira/binary-search-tree/workflows/CI/badge.svg)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)

## Objetivo
Desenvolver uma aplicação em linguagem C para dar manutenção em um cadastro de nomes de pessoas
armazenado em memória RAM usando uma árvore de pesquisa binária.
## Descrição
O programa, ao ser iniciado, deverá carregar uma base de dados de nomes inicial a partir de um arquivo texto.
Cada nome, com não mais que 30 caracteres, deverá ser inserido em uma árvore de pesquisa binária mantida
em memória RAM através de uma chamada à operação inserir, usando como chave o próprio nome.

A tela do programa deverá fornecer um menu para permitir as seguintes operações:
1. Recarregar a listagem de nomes a partir do arquivo. Para tanto, todo o conteúdo da árvore anterior
deverá ser removido e uma nova carga deverá ser feita, como descrito acima.
2. Listar todos os nomes em ordem alfabética.
3. Listar todos os nomes que contém uma substring fornecida.
4. Inserir um novo nome na memória.
5. Remover um nome da memória.
6. Listar e remover da memória todos os nomes que são maiores, em ordem alfabética, que um nome
fornecido.
7. Listar e remover da memória todos os nomes que são menores, em ordem alfabética, que um nome
fornecido.
8. Salvar o conteúdo da memória em um arquivo texto.
Para facilitar a implementação, armazene todas os nomes em letras minúsculas, e considere as entradas
fornecidas nas operações como sendo minúsculas. 
