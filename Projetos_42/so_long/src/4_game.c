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
		ft_close_window(sl);
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

int	ft_next_move(t_sl *sl)
{
	int	a;

	a = 1;
	if (sl->map.str[sl->map.yp + sl->ay][sl->map.xp + sl->ax] == '1')
		{
			ft_printf("	Reversed Monobra, collision in sight! \n");
			a = 0;
		}
	if (sl->map.str[sl->map.yp + sl->ay][sl->map.xp + sl->ax] == 'C')
		{
			ft_printf("	Congrats item collected successfully ✓\n");
			sl->map.char_c --;
			if (sl->map.char_c == 0)
				ft_printf("	Mission completed, you're ready for the wormhole! ✓\n");
		}
	if (sl->map.str[sl->map.yp + sl->ay][sl->map.xp + sl->ax] == 'E')
		{
			if (sl->map.char_c == 0)
			{
				ft_printf("	Mission accomplished, return to "
					"your post cadet ! ✓\n");
				ft_close_window(sl);
			}
			else
			ft_printf("	 ▥ You are not prepared for the wormhole !"
				"Go back and collect the %d remaining collectibles!\n"
				"", sl->map.char_c );
			a = 0;
		}
	if (a == 1)
	{
		sl->map.str[sl->map.yp + sl->ay][sl->map.xp + sl->ax] = 'P';
		sl->map.str[sl->map.yp][sl->map.xp] = '0';
		mlx_put_image_to_window(sl->win.ptr, sl->win.scr, sl->img.mlx_img_0,
			(sl->map.xp * DIS), (sl->map.yp * DIS));
		mlx_put_image_to_window(sl->win.ptr, sl->win.scr, sl->img.mlx_img_P,
			((sl->map.xp + sl->ax) * DIS), ((sl->map.yp + sl->ay) * DIS));
		sl->map.xp += sl->ax;
		sl->map.yp += sl->ay;
	}
	return(a);
}

void ft_print_steps(t_sl *sl)
{
		sl->steps++;
		ft_printf("	steps: %d \n",sl->steps);
}
