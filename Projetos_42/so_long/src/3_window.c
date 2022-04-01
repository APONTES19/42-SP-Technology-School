/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:50:33 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/23 16:37:00 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_win(t_sl *sl)
{
	sl->win.ptr = mlx_init();
	if (sl->win.ptr == NULL)
		ft_error_win(sl, 12);
	sl->win.x = (DIS * sl->map.columns);
	sl->win.y = (DIS * sl->map.line);
	sl->win.scr = mlx_new_window (sl->win.ptr, sl->win.x, sl->win.y, "so_long");
	if (sl->win.scr == NULL)
		ft_error_win(sl, 12);
	ft_set_img(sl);
	ft_render(sl);
	mlx_key_hook(sl->win.scr, &ft_key, sl);
	mlx_hook(sl->win.scr, 33, 1L << 17, &ft_close_x, sl);
	mlx_expose_hook(sl->win.scr, &ft_render, sl);
	mlx_loop(sl->win.ptr);
}

void	ft_set_img(t_sl *sl)
{
	sl->img.mlx_img_1 = mlx_xpm_file_to_image(sl->win.ptr,
			"./img/1.xpm", &sl->img.x, &sl->img.y);
	if (sl->img.mlx_img_1 == NULL)
		ft_error_win(sl, 13);
	sl->img.mlx_img_0 = mlx_xpm_file_to_image(sl->win.ptr,
			"./img/0.xpm", &sl->img.x, &sl->img.y);
	if (sl->img.mlx_img_0 == NULL)
		ft_error_win(sl, 14);
	sl->img.mlx_img_c = mlx_xpm_file_to_image(sl->win.ptr,
			"./img/C.xpm", &sl->img.x, &sl->img.y);
	if (sl->img.mlx_img_c == NULL)
		ft_error_win(sl, 15);
	sl->img.mlx_img_e = mlx_xpm_file_to_image(sl->win.ptr,
			"./img/E.xpm", &sl->img.x, &sl->img.y);
	if (sl->img.mlx_img_e == NULL)
		ft_error_win(sl, 16);
	sl->img.mlx_img_p = mlx_xpm_file_to_image(sl->win.ptr,
			"./img/P.xpm", &sl->img.x, &sl->img.y);
	if (sl->img.mlx_img_p == NULL)
		ft_error_win(sl, 17);
	sl->img.mlx_img_b = mlx_xpm_file_to_image(sl->win.ptr,
			"./img/b.xpm", &sl->img.x, &sl->img.y);
	if (sl->img.mlx_img_b == NULL)
		ft_error_win(sl, 18);
	ft_printf("	Set image ✓\n");
}

int	ft_render(t_sl *sl)
{
	sl->ay = 0;
	while (sl->ay < sl->map.line)
	{
		sl->ax = 0;
		while (sl->ax < sl->map.columns)
		{
			if (sl->map.str[sl->ay][sl->ax] == '1')
				ft_put_render(sl, sl->img.mlx_img_1);
			if (sl->map.str[sl->ay][sl->ax] == '0')
				ft_put_render(sl, sl->img.mlx_img_0);
			if (sl->map.str[sl->ay][sl->ax] == 'C')
				ft_put_render(sl, sl->img.mlx_img_c);
			if (sl->map.str[sl->ay][sl->ax] == 'E')
				ft_put_render(sl, sl->img.mlx_img_e);
			if (sl->map.str[sl->ay][sl->ax] == 'P')
				ft_put_render(sl, sl->img.mlx_img_p);
			sl->ax++;
		}
		sl->ay++;
	}
	return (0);
}

void	ft_put_render(t_sl *sl, t_sl *img)
{
	mlx_put_image_to_window(sl->win.ptr, sl->win.scr,
		img, (sl->ax * DIS), (sl->ay * DIS));
}

void	ft_check_p(t_sl *sl)
{
	sl->ay = 0;
	while (sl->ay < sl->map.line)
	{
		sl->ax = 0;
		while (sl->ax < sl->map.columns)
		{
			if (sl->map.str[sl->ay][sl->ax] == 'P')
			{
				sl->map.xp = sl->ax;
				sl->map.yp = sl->ay;
			}
			sl->ax++;
		}
		sl->ay++;
	}
}
