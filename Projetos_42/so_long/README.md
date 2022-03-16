Projeto So_Long , reproduzir um jogo 2d utilizando a biblioteca minilibx

Preparar a máquina para rodar a minilibx
cd ./libs/mlk
./configure


para compilar os testes da minilibx use as flags

clang abrir_tela_mlx.c  -I ../lib/mlx/ -L ../lib/mlx/ -lmlx -Ilmlx -lXext -lX11 ../lib/mlx/libmlx.a

clang ==> compilador pode ser com o gcc também !
abrir_tela_mlx.c  ==> arquivo a ser compilado
-I ../lib/mlx/   ==> caminho dos includes
-L ../lib/mlx/   ==> caminho das Bibliotecas
-lmlx ==> comando da biblioteca
-Ilmlx ==> comando da biblioteca
-lXext ==> comando da biblioteca
-lX11 ../lib/mlx/libmlx.a  ==> caminho da biblioteca mlx

Compilando o game so_longo
make

Para rodar o game

