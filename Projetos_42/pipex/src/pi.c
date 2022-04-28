/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:56:20 by lucasmar          #+#    #+#             */
/*   Updated: 2022/04/25 19:26:18 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pipex.h>

int	teste(void)
{
	int	pid;
	int	fd[2];
	int	pepi;
	char	saida[6];

	pepi = pipe(fd);
	if(pepi == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(0);
	}
	if (pid > 0)
	{
		wait(&pid);
		ft_printf("\nPROCESSO PAI:\n");
		read(fd[0], &saida, 6);
		ft_printf("Valor no Pipe filho: %s",saida);
		close(fd[0]);
	}
	else
	{
		write(fd[1],"LUCAS\n",6);
		ft_printf("\nPROCESSO FILHO:\n");
		close(fd[1]);
		//execve("/bin/bash/ls -la", NULL);
	}
	ft_printf("COMUM DOS PROCESSOS!\n");
	return (0);
}
