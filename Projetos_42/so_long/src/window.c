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

	sl->win.x = (D_IMG_SIZE * sl->map.columns);
	sl->win.y = (D_IMG_SIZE * sl->map.line);

	sl->win.scr = mlx_new_window(sl->win.ptr,
		sl->win.x, sl->win.y,"so_long");
	if (sl->win.scr == NULL)
		ft_error_win(12);


	ft_set_img(sl);
	ft_render(sl);

	mlx_expose_hook(sl->win.scr, ft_render, &sl);

	mlx_hook(sl->win.scr, 33, 1L << 17, ft_close_window, &sl);
	mlx_key_hook(sl->win.scr, ft_key, &sl);


	mlx_loop(sl->win.ptr);
}

int	ft_close_window(t_sl *sl)
{
	mlx_destroy_window(sl->win.ptr, sl->win.scr);
	return (0);
}

int	ft_render(t_sl *sl)
{
	size_t	x;
	size_t	y;

	y = 0;
	while(y < sl->map.line)
	{
		x = 0;
		while(x < sl->map.columns)
		{
			if (sl->map.str[y][x]== '1')
				mlx_put_image_to_window(sl->win.ptr, sl->win.scr,
					sl->img.mlx_img_1, (x * D_IMG_SIZE), (y * D_IMG_SIZE));
			if (sl->map.str[y][x] == '0')
				mlx_put_image_to_window(sl->win.ptr, sl->win.scr,
					sl->img.mlx_img_0, (x * D_IMG_SIZE), (y * D_IMG_SIZE));
			if (sl->map.str[y][x] == 'C')
				mlx_put_image_to_window(sl->win.ptr, sl->win.scr,
					sl->img.mlx_img_C, (x * D_IMG_SIZE), (y * D_IMG_SIZE));
			if (sl->map.str[y][x] == 'E')
				mlx_put_image_to_window(sl->win.ptr, sl->win.scr,
					sl->img.mlx_img_E, (x * D_IMG_SIZE), (y * D_IMG_SIZE));
			if (sl->map.str[y][x] == 'P')
				mlx_put_image_to_window(sl->win.ptr, sl->win.scr,
					sl->img.mlx_img_P, (x * D_IMG_SIZE), (y * D_IMG_SIZE));
			x++;
		}
		y++;
	}
	ft_printf("	▥ render game ✓\n");
	return(0);
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
	ft_printf("	▥ Set image ✓\n");
}
