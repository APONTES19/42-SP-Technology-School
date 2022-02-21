#include<stdio.h>
#include<stdlib.h>

int Warning(int n_erro);

int	main(int argc , char **argv)
{
	if (argc != 2)
		warning(1);
	if()
		warning(2);
	return(0);
}

int Warning(int n_warning)
{
	if (n_warning== 1)
		printf("\nErro x1!\nPor Favor,compilar com 2 argumentos\n\n");
	exit(0);
}
