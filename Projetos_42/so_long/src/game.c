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
	int	x;
	int	y;

	x = -1;
	y = 0;
	if (ft_next_move(sl, x, y) == 1)
	{
		sl->steps++;
		ft_printf("	steps: %d \n",sl->steps);
	}
}

void	ft_move_rigth(t_sl *sl)
{
	int	x;
	int	y;

	x = 1;
	y = 0;
	if (ft_next_move(sl, x, y) == 1)
	{
		sl->steps++;
		ft_printf("	steps: %d \n",sl->steps);
	}
}

void	ft_move_up(t_sl *sl)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	if (ft_next_move(sl, x, y) == 1)
	{
		sl->steps++;
		ft_printf("	steps: %d \n",sl->steps);
	}
}

void	ft_move_down(t_sl *sl)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	if (ft_next_move(sl, x, y) == 1)
	{
		sl->steps++;
		ft_printf("	steps: %d \n",sl->steps);
	}
}

int	ft_next_move(t_sl *sl, int x, int y)
{
	int	a;

	a = 1;
	if (sl->map.str[sl->map.yp + y][sl->map.xp + x] == '1')
		{
			ft_printf("	Reversed Monobra, collision in sight! \n");
			a = 0;
		}
	if (sl->map.str[sl->map.yp + y][sl->map.xp + x] == 'C')
		{
			ft_printf("	Congrats item collected successfully ✓\n");
			sl->map.char_c --;
			if (sl->map.char_c == 0)
				ft_printf("	Mission completed, you're ready for the wormhole! ✓\n");
		}
	if (sl->map.str[sl->map.yp + y][sl->map.xp + x] == 'E')
		{
			if (sl->map.char_c == 0)
			{
				ft_printf("	Mission accomplished, return to "
					"your post cadet ! ✓\n");
				ft_close_window(sl);
			}
			else
			ft_printf("	You are not prepared for the wormhole !"
				"Go back and collect the %d remaining collectibles!\n"
				"", sl->map.char_c );
			a = 0;
		}
	if (a == 1)
	{
		sl->map.str[sl->map.yp + y][sl->map.xp + x] = 'P';
		sl->map.str[sl->map.yp][sl->map.xp] = '0';
		mlx_put_image_to_window(sl->win.ptr, sl->win.scr, sl->img.mlx_img_0,
			(sl->map.xp * D_IMG_SIZE), (sl->map.yp * D_IMG_SIZE));
		mlx_put_image_to_window(sl->win.ptr, sl->win.scr, sl->img.mlx_img_P,
			((sl->map.xp + x) * D_IMG_SIZE), ((sl->map.yp + y) * D_IMG_SIZE));
		sl->map.xp += x;
		sl->map.yp += y;
	}
	return(a);
}

int	ft_close_window(t_sl *sl)
{
	mlx_destroy_window(sl->win.ptr, sl->win.scr);
	return (0);
}
