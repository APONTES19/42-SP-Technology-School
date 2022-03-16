/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_mostrando_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:49:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/02/21 15:05:51 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

typedef struct window
{
	void	*mlx_ptr;
	void	*win;
	int		y;
	int		x;
}			t_struct;

int	main(void)
{
	t_struct	window;
	void *img;
	int *i_x;
	int *i_y;

	window.mlx_ptr = mlx_init();
	window.win = mlx_new_window(window.mlx_ptr, 400, 800, "My firt window");
	i_x = 0;
	i_y = 0;
	img = mlx_xpm_file_to_image(window.mlx_ptr,"./img/falcon.xpm",i_x,i_y);
	mlx_put_image_to_window(window.mlx_ptr, window.win, img,window.x,window.y);
	mlx_loop(window.mlx_ptr);
}
