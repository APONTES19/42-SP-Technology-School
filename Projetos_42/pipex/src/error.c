/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:27:18 by lucasmar          #+#    #+#             */
/*   Updated: 2022/04/29 10:58:22 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pipex.h>

void	ft_error_arg(t_px *px, int n, int exit)
{
	if (n == 1)
		ft_printf("error number of arguments different off 4!\n");
	if (n == 2)
	{
		n = 0;
		perror(px->arg.infile);
	}
	if (n == 3)
		perror(px->arg.outfile);
	if (n == 4)
	{
		n = 0;
		ft_printf("%s: command not found\n", px->arg.cmd1[0]);
	}
	if (n == 5)
	{
		n = 0;
		ft_printf("%s: command not found\n", px->arg.cmd2[0]);
	}

	ft_zero_leak(px, n);
	ft_select_exit(exit);
}

void	ft_error_process(int n)
{
	char	*msg;

	msg = NULL;
	if (n == 1)
		msg = "	Error no fork!";
	if (n == 2)
		msg = "	Error no pipe!";
	write(1,"\033[0;31m \n       (error x",24);
	ft_printf("%d",n);
	write(1,") Process error!\n\n",20);
	ft_printf("%s", msg);
	write(1,"\033[0;31 \n	CCheck the process and try again!\n\n\033[0m",45);
}
void	ft_zero_leak (t_px *px, int n)
{
	int i;
	if (n > 10)
	{
		//função achar caminho do path
		i = -1;
		while(px->path_envp[++i])
			free(px->path_envp[i]);
		free(px->path_envp);

		//função check command 1 dos argumentos
		i = -1;
		while(px->arg.cmd1[++i])
			free(px->arg.cmd1[i]);
		free(px->arg.cmd1);
		free(px->path_cmd1);

		//função check command 2 dos argumentos
		i = -1;
		while(px->arg.cmd2[++i])
			free(px->arg.cmd2[i]);
		free(px->arg.cmd2);
		free(px->path_cmd2);

		// zerando os lixos de mémoria.
		ft_memset (px, 0, sizeof(px));
	}
}

void	ft_select_exit(int n)
{
	exit(n);
}
