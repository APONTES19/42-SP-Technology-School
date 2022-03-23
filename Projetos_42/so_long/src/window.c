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
	sl->win.scr = mlx_new_window(sl->win.ptr, sl->win.x, sl->win.y,"so_long");
	if (sl->win.scr == NULL)
		ft_error_win(12);
	ft_render(sl);
	mlx_hook(sl->win.ptr, 17, 0, ft_close_window, &sl);
	mlx_key_hook(sl->win.ptr, &ft_key, sl);
	mlx_loop(sl->win.ptr);

}

int	ft_close_window(t_sl *sl)
{
	mlx_destroy_window(sl->win.ptr, sl->win.scr);
	return (0);
}

int	ft_key(int key, t_sl *sl)
{
	if (key == 65307)
		ft_close_window(sl);
	return (0);
}

void	ft_render(t_sl *sl)
{
	size_t	i_x;
	size_t	i_y;
	size_t	c;

	i_y = 0;
	c = 0;
	while(i_y <= sl->map.line)
	{
		i_x = 0;
		while(i_x <= sl->map.columns)
		{
			if (sl->map.string[c] == '1')
				mlx_put_image_to_window(sl->win.ptr, sl->win.scr,
					sl->img.mlx_img_1, (i_x * D_IMG_SIZE), (i_y * D_IMG_SIZE));
			if (sl->map.string[c] == '0')
				mlx_put_image_to_window(sl->win.ptr, sl->win.scr,
					sl->img.mlx_img_0, (i_x * D_IMG_SIZE), (i_y * D_IMG_SIZE));
			if (sl->map.string[c] == 'C')
				mlx_put_image_to_window(sl->win.ptr, sl->win.scr,
					sl->img.mlx_img_C, (i_x * D_IMG_SIZE), (i_y * D_IMG_SIZE));
			if (sl->map.string[c] == 'E')
				mlx_put_image_to_window(sl->win.ptr, sl->win.scr,
					sl->img.mlx_img_E, (i_x * D_IMG_SIZE), (i_y * D_IMG_SIZE));
			if (sl->map.string[c] == 'P')
				mlx_put_image_to_window(sl->win.ptr, sl->win.scr,
					sl->img.mlx_img_P, (i_x * D_IMG_SIZE), (i_y * D_IMG_SIZE));
			c++;
			i_x++;
		}
		i_y++;
	}
}

void	ft_set_img(t_sl *sl)
{
	sl->img.mlx_img_1 = NULL;
	sl->img.mlx_img_0 = NULL;
	sl->img.mlx_img_C = NULL;
	sl->img.mlx_img_E = NULL;
	sl->img.mlx_img_P = NULL;

	sl->img.mlx_img_1 = mlx_xpm_file_to_image(sl->win.ptr,
		".img/1.xpm",&sl->img.x, &sl->img.y);
	if(sl->img.mlx_img_1 == NULL)
		ft_error_win(13);


	// sl->img.mlx_img_0= mlx_xpm_file_to_image(sl->win.ptr,
	// 	"./img/0.xpm",&sl->img.x, &sl->img.y);
	// if(sl->img.mlx_img_0 == NULL)
	// 	ft_error_win(13);


	// sl->img.mlx_img_C= mlx_xpm_file_to_image(sl->win.ptr,
	// 	"./img/C.xpm",&sl->img.x, &sl->img.y);
	// if(sl->img.mlx_img_C == NULL)
	// 	ft_error_win(13);


	// sl->img.mlx_img_E = mlx_xpm_file_to_image(sl->win.ptr,
	// 	"./img/E.xpm",&sl->img.x, &sl->img.y);
	// if(sl->img.mlx_img_E == NULL)
	// 	ft_error_win(13);


	// sl->img.mlx_img_P = mlx_xpm_file_to_image(sl->win.ptr,
	// 	"./img/P.xpm",&sl->img.x, &sl->img.y);
	// if(sl->img.mlx_img_P == NULL)
	// 	ft_error_win(13);
}
