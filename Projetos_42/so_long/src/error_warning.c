/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_warning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:33:44 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/23 15:52:09 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_input(t_sl *sl, int n_error)
{
	if (n_error == 1)
		ft_printf("	(error x1)\n	Please, execute with just one argument "
			"valid '.ber'!\n\n");
	if (n_error == 2)
		ft_printf("	(error x2)\n	Is only accepted "
			"map with the extension \".ber\"!\n\n");
	if (n_error == 3)
		ft_printf("	(error x3)\n	Map not found or invalid "
			"please check !\n\n");
	ft_printf("	↻ check the argument and try again! ex: ./maps/x.ber !"
		" - by Lucasmar 42sp\n\n");
	ft_close_window(sl);
}

void	ft_error_map(t_sl *sl, int n_error)
{
	if (n_error == 4)
		ft_printf("	(error x4)\n	Reading empty or Memory Allocation!\n");
	if (n_error == 6)
		ft_printf("	(error x6)\n	Number of lines, minimum 3 on the map!\n");
	if (n_error == 7)
		ft_printf("	(error x7)\n	Column number, minimum 3 on the map!\n");
	if (n_error == 8)
		ft_printf("	(error x8)\n	Invalid format! must be rectangular!\n");
	if (n_error == 9)
		ft_printf("	(error x9)\n	Mandatory character '1' missing!\n");
	if (n_error == 10)
		ft_printf("	(error x10)\n	character not allowed\n");
	if (n_error == 11)
		ft_printf("\n	(error x11)\n	Map is not surrounded by a wall!\n");
	ft_printf("	↻ Check the map and try again! - by Lucasmar 42sp\n\n");
	if (n_error == 18)
		ft_printf("	(error x18)\n	Mandatory character '0' missing!\n");
	if (n_error == 19)
		ft_printf("	(error x19)\n	Mandatory character 'C' missing!\n");
	if (n_error == 20)
		ft_printf("	(error x20)\n	Mandatory character 'E' missing!\n");
	if (n_error == 21)
		ft_printf("	(error x21)\n	Mandatory character 'P' missing!\n");
	ft_close_window(sl);
}

void	ft_error_win(t_sl *sl, int n_error)
{
	if (n_error == 12)
		ft_printf("\n	(error x12)\n	Falha ao iniciar janela!\n");
	if (n_error == 13)
		ft_printf("\n	(error x13)\n	Failed to load image! 'WALL 1'!\n");
	if (n_error == 14)
		ft_printf("\n	(error x14)\n	Failed to load image! 'EMPTY 0'\n");
	if (n_error == 15)
		ft_printf("\n	(error x15)\n	Failed to load img!'COLLECTIBLE C'\n");
	if (n_error == 16)
		ft_printf("\n	(error x16)\n	Failed to load image! 'EXIT E'\n");
	if (n_error == 17)
		ft_printf("\n	(error x17)\n	Failed to load image! 'START P'\n");
	ft_printf("	↻ Check the error and try again!"
		" - by Lucasmar 42sp\n\n");
	ft_close_window (sl);
}

int	ft_close_window(t_sl *sl)
{
	ft_memset(&sl, 0, sizeof sl);
	exit(3);
	return (0);
}
