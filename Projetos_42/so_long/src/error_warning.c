/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_warning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:33:44 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/16 14:59:06 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_input(int n_error)
{
	if (n_error == 1)
		ft_printf("	(error x1)\n	Please, run by adding a "
			"valid map ! \".ber\"!\n\n");
	if (n_error == 2)
		ft_printf("	(error x2)\n	Please, run with just one "
			"valid map !\n\n");
	if (n_error == 3)
		ft_printf("	(error x3)\n	Is only accepted "
			"map with the extension \".ber\"!\n\n");
	if (n_error == 4)
		ft_printf("	(error x4)\n	Map not found or invalid "
			"please check !\n\n");
	ft_printf("	↻ Verifique o argumento e tente novamente !"
		" - by Lucasmar 42sp\n\n");
	exit(EXIT_FAILURE);
}

void	ft_error_map(int n_error)
{
	if (n_error == 5)
		ft_printf("	(error x5)\n	Reading or Memory Allocation!\n");
	if (n_error == 6)
		ft_printf("	(error x6)\n	Number of lines, minimum 3 on the map!\n");
	if (n_error == 7)
		ft_printf("	(error x7)\n	Column number, minimum 3 on the map!\n");
	if (n_error == 8)
		ft_printf("	(error x8)\n	Invalid format! must be rectangular!\n");
	if (n_error == 9)
		ft_printf("	(error x9)\n	Mandatory character missing!\n");
	if (n_error == 10)
		ft_printf("	(error x10)\n	character not allowed\n");
	if (n_error == 11)
		ft_printf("\n	(error x11)\n	Map is not surrounded by a wall!\n");
	ft_printf("	↻ Check the map and try again!"
		" - by Lucasmar 42sp\n\n");
	exit(EXIT_FAILURE);
}

void	ft_error_win(int n_error)
{
	if (n_error == 12)
		ft_printf("\n	(error x12)\n	Falha ao iniciar janela! \n");
	ft_printf("	↻ Check the map and try again!"
		" - by Lucasmar 42sp\n\n");
}
