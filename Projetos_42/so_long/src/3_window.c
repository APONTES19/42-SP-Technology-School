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
		ft_error_win(12);
	sl->win.x = (DIS * sl->map.columns);
	sl->win.y = (DIS * sl->map.line);
	sl->win.scr = mlx_new_window(sl->win.ptr,
		sl->win.x, sl->win.y,"so_long");
	if (sl->win.scr == NULL)
		ft_error_win(12);
	ft_set_img(sl);
	ft_render(sl);
	mlx_key_hook(sl->win.scr, &ft_key, sl);
	mlx_hook(sl->win.scr, 33, 1L << 17, &ft_close_window, &sl);
	mlx_expose_hook(sl->win.scr, &ft_render, sl);
	mlx_loop(sl->win.ptr);
}

void	ft_set_img(t_sl *sl)
{
	sl->img.mlx_img_1 = mlx_xpm_file_to_image(sl->win.ptr,
		"./img/1.xpm",&sl->img.x, &sl->img.y);
	if(sl->img.mlx_img_1 == NULL)
		ft_error_win(13);
	sl->img.mlx_img_0= mlx_xpm_file_to_image(sl->win.ptr,
		"./img/0.xpm",&sl->img.x, &sl->img.y);
	if(sl->img.mlx_img_0 == NULL)
		ft_error_win(14);
	sl->img.mlx_img_C= mlx_xpm_file_to_image(sl->win.ptr,
		"./img/C.xpm",&sl->img.x, &sl->img.y);
	if(sl->img.mlx_img_C == NULL)
		ft_error_win(15);
	sl->img.mlx_img_E = mlx_xpm_file_to_image(sl->win.ptr,
		"./img/E.xpm",&sl->img.x, &sl->img.y);
	if(sl->img.mlx_img_E == NULL)
		ft_error_win(16);
	sl->img.mlx_img_P = mlx_xpm_file_to_image(sl->win.ptr,
		"./img/P.xpm",&sl->img.x, &sl->img.y);
	if(sl->img.mlx_img_P == NULL)
		ft_error_win(17);
	sl->steps = 0;
	ft_printf("	Set image ✓\n");
}

int	ft_render(t_sl *sl)
{
	sl->ay = 0;
	while(sl->ay < sl->map.line)
	{
		sl->ax = 0;
		while(sl->ax < sl->map.columns)
		{
			if (sl->map.str[sl->ay][sl->ax] == '1')
				mlx_put_image_to_window(sl->win.ptr, sl->win.scr,
					sl->img.mlx_img_1, (sl->ax * DIS), (sl->ay * DIS));
			if (sl->map.str[sl->ay][sl->ax] == '0')
				mlx_put_image_to_window(sl->win.ptr, sl->win.scr,
					sl->img.mlx_img_0, (sl->ax * DIS), (sl->ay * DIS));
			if (sl->map.str[sl->ay][sl->ax] == 'C')
				mlx_put_image_to_window(sl->win.ptr, sl->win.scr,
					sl->img.mlx_img_C, (sl->ax * DIS), (sl->ay * DIS));
			if (sl->map.str[sl->ay][sl->ax] == 'E')
				mlx_put_image_to_window(sl->win.ptr, sl->win.scr,
					sl->img.mlx_img_E, (sl->ax * DIS), (sl->ay * DIS));
			if (sl->map.str[sl->ay][sl->ax] == 'P')
				mlx_put_image_to_window(sl->win.ptr, sl->win.scr,
					sl->img.mlx_img_P, (sl->ax * DIS), (sl->ay * DIS));
			sl->ax++;
		}
		sl->ay++;
	}
	ft_printf("	terminei!\n");
	return(0);
}
