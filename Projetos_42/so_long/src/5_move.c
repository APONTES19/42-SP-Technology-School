/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:33:44 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/23 15:52:09 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_next_move(t_sl *sl)
{
	sl->aux = 1;
	if (sl->map.str[sl->map.yp + sl->ay][sl->map.xp + sl->ax] == '1')
		ft_move_if_1(sl);
	if (sl->map.str[sl->map.yp + sl->ay][sl->map.xp + sl->ax] == 'C')
	{
		ft_printf("	Congrats item collected successfully ✓\n");
		sl->map.char_c --;
	}
	if (sl->map.str[sl->map.yp + sl->ay][sl->map.xp + sl->ax] == 'E')
	{
		if (sl->map.char_c == 0)
		{
			ft_printf("	Mission accomplished, return to your post cadet ! ✓\n");
			ft_close_window(sl, 20);
		}
		else
			ft_printf("	▥Not prepared collect %d remaining\n", sl->map.char_c);
		sl->aux = 0;
	}
	if (sl->aux == 1)
		ft_move(sl);
	return (sl->aux);
}

void	ft_move(t_sl *sl)
{
	sl->map.str[sl->map.yp + sl->ay][sl->map.xp + sl->ax] = 'P';
	sl->map.str[sl->map.yp][sl->map.xp] = '0';
	mlx_put_image_to_window(sl->win.ptr, sl->win.scr, sl->img.mlx_img_0,
		(sl->map.xp * DIS), (sl->map.yp * DIS));
	mlx_put_image_to_window(sl->win.ptr, sl->win.scr, sl->img.mlx_img_p,
		((sl->map.xp + sl->ax) * DIS), ((sl->map.yp + sl->ay) * DIS));
	sl->map.xp += sl->ax;
	sl->map.yp += sl->ay;
}

void	ft_move_if_1(t_sl *sl)
{
	if (sl->n == 0)
		ft_printf("	Attention we suffered damage in the"
			" next collision we lost the ship! \n");
	else
	{
		sl->aux = 100000;
		while (sl->aux != 0)
		{
			mlx_put_image_to_window(sl->win.ptr, sl->win.scr, sl->img.mlx_img_0,
				(sl->map.xp * DIS), (sl->map.yp * DIS));
			mlx_put_image_to_window(sl->win.ptr, sl->win.scr, sl->img.mlx_img_b,
				(sl->map.xp * DIS), (sl->map.yp * DIS));
		sl->aux--;
		}
		ft_printf("	GAME OVER !!!\n");
		ft_close_window(sl, 20);
	}
	sl->aux = 0;
	sl->n++;
}

void	ft_print_steps(t_sl *sl)
{
	sl->steps++;
	ft_printf("	steps: %d \n", sl->steps);
}
