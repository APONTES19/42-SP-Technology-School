Projeto So_Long , reproduzir um desenho 2d utilizando uma biblioteca minilibx

Usando preparando a máquina para rodar a minilibx
./configure
assim dentro da pasta lib/mlx/

para compilar os testes use as flags

clang abrir_tela_mlx.c  -I ../lib/mlx/ -L ../lib/mlx/ -lmlx -Ilmlx -lXext -lX11 ../lib/mlx/libmlx.a

clang ==> compilador pode ser com o gcc também !
abrir_tela_mlx.c  ==> arquivo a ser compilado
-I ../lib/mlx/   ==> caminho dos includes
-L ../lib/mlx/   ==> caminho das Bibliotecas
-lmlx ==> comando da biblioteca
-Ilmlx ==> comando da biblioteca
-lXext ==> comando da biblioteca
-lX11 ../lib/mlx/libmlx.a  ==> caminho da biblioteca mlx

