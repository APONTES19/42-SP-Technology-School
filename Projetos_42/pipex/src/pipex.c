/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:17:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/04/23 01:09:27 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pipex.h>

int	main (int argc, char **argv, char **envp)
{
	t_px	px;

	ft_memset (&px, 0, sizeof(px));
	ft_check_input (argc, argv, envp, &px);
	if(argv)
		return (0);
	if (argc)
		return (0);
	return (0);
}
