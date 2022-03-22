/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:50:33 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/22 14:45:30 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_win(t_sl *sl)
{
	sl->win.ptr = mlx_init();
	if (sl->win.ptr == NULL)
		ft_error_win(12);
	sl->win.x = (D_IMG_SIZE * sl->map.line);
	sl->win.y = (D_IMG_SIZE * sl->map.columns);
	sl->win.scr = mlx_new_window(sl->win.ptr, sl->win.x, sl->win.y,
		"so_long by Lucas Martins 42sp");
	if (sl->win.scr == NULL)
		ft_error_win(12);

	//chamar função de imagem!!
	sl->img.mlx_img = mlx_xpm_file_to_image(sl->win.ptr, "./img/perfil-42.xpm",
	&sl->img.x, &sl->img.y);
	mlx_put_image_to_window(sl->win.ptr, sl->win.scr, sl->img.mlx_img, 10, 10);

	mlx_hook(sl->win.ptr, 33, 1L << 17, &ft_close_window, &sl);
	mlx_key_hook(sl->win.ptr, &ft_key, &sl);

	mlx_loop(sl->win.ptr);

	mlx_destroy_image(sl->win.ptr, sl->img.mlx_img);
	mlx_destroy_display(sl->win.ptr);
	free(sl->win.ptr);
}

int	ft_close_window(t_sl *sl)
{
	mlx_destroy_window(sl->win.ptr, sl->win.scr);
	sl->win.ptr = NULL;
	printf("\nFECHEI\n");
	return (0);
}

int	ft_key(int key, t_sl *sl)
{
	if (key == 65307)
		ft_close_window(sl);
	printf("\nKEY: %d %s\n", key, sl->win.ptr);
	return (0);
}
