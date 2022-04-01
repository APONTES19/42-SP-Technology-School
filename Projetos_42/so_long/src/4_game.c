/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:33:44 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/23 15:52:09 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key(int key, t_sl *sl)
{
	if (key == 65307)
		ft_close_window(sl, 20);
	else if (key == D_A || key == D_L)
		ft_move_left(sl);
	else if (key == D_D || key == D_R)
		ft_move_rigth(sl);
	else if (key == D_W || key == D_U)
		ft_move_up(sl);
	else if (key == D_S || key == D_DOWN)
		ft_move_down(sl);
	else
		ft_printf("\n	Use the keys to move\n\n"
			"                 w     \n"
			"                 ▲     \n"
			"             a ◀   ▶ d \n"
			"                 ▼     \n"
			"                 s   \n\n"
			"	Mission: Collect all collectibles and exit the wormhole!\n");
	return (0);
}

void	ft_move_left(t_sl *sl)
{
	sl->ax = -1;
	sl->ay = 0;
	if (ft_next_move(sl) == 1)
		ft_print_steps(sl);
}

void	ft_move_rigth(t_sl *sl)
{
	sl->ax = 1;
	sl->ay = 0;
	if (ft_next_move(sl) == 1)
		ft_print_steps(sl);
}

void	ft_move_up(t_sl *sl)
{
	sl->ax = 0;
	sl->ay = -1;
	if (ft_next_move(sl) == 1)
		ft_print_steps(sl);
}

void	ft_move_down(t_sl *sl)
{
	sl->ax = 0;
	sl->ay = 1;
	if (ft_next_move(sl) == 1)
		ft_print_steps(sl);
}
