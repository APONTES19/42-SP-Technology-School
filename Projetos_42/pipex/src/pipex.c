/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:17:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/04/30 12:00:27 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pipex.h>

int	main (int argc, char **argv, char **envp)
{
	t_px	px;

	ft_memset (&px, 0, sizeof(px));
	px.pid_1 = -2;
	px.pid_2 = -2;
	ft_check_input (argc, argv, envp, &px);
	ft_process(argc, argv, envp, &px);
	return (0);
}

