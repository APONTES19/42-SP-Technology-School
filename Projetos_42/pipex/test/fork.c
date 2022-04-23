/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:56:20 by lucasmar          #+#    #+#             */
/*   Updated: 2022/04/14 11:27:05 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pipex.h>

int	main(void)
{
	t_px	px;

	px.a = 10;
	px.pid = fork();
	if (px.pid < 0)
	{
		perror("fork");
		exit(0);
	}
	if (px.pid > 0)
	{
		wait(&px.pid);
		px.a = 50;
		ft_printf("\nPROCESSO PAI %d %p\n", px.a &px.a);
	}
	else
	{
		ft_printf("\nPROCESSO FILHO %d %p\n", px.a &px.a);
	}
	ft_printf("COMUM DOS PROCESSOS! %d %p\n", px.a &px.a);
	return (0);
}
