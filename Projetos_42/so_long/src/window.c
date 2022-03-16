/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:50:33 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/16 17:35:03 by lucasmar         ###   ########.fr       */
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
	sl->img.mlx_img = mlx_new_image(sl->win.ptr, sl->win.x, sl->win.y);
	if (!sl->img.mlx_img)
		ft_error_win(12);
	sl->img.addr = mlx_get_data_addr(sl->img.mlx_img, &sl->img.bpp,
	&sl->img.line_len, &sl->img.endian);
	//mlx_loop(sl->win.ptr);
}
