/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:49:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/22 13:55:59 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>

/*Compile with
clang 1_open_window.c -I ../libs/mlx -L ../libs/mlx -lmlx -Ilmlx -lXext -lX11
../libs/mlx/libmlx.a -O 2_close_window_boton*/

typedef struct image
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		s_x;
	int		s_y;
}	t_img;

typedef struct window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}			t_win;

int		ft_close_window(t_win *win);
int		ft_key(int key, t_win *win);

int	main(void)
{
	t_win	win;

	win.mlx_ptr = mlx_init();
	if (win.mlx_ptr == NULL)
		exit(EXIT_FAILURE);

	win.win_ptr = mlx_new_window(win.mlx_ptr, 800, 800, "My firt window");
	if (win.win_ptr == NULL)
	{
		free(win.win_ptr);
		exit(EXIT_FAILURE);
	}

	/*images*/
	win.img.mlx_img = mlx_xpm_file_to_image(win.mlx_ptr, "../img/perfil-42.xpm",
	&win.img.s_x, &win.img.s_y);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.img.mlx_img, 0, 0);

	/*events*/
	mlx_hook(win.win_ptr, 33, 1L << 17, ft_close_window, &win);
	mlx_key_hook(win.win_ptr, &ft_key, &win);

	mlx_loop(win.mlx_ptr);

	/*after close window*/
	mlx_destroy_image(win.mlx_ptr, win.img.mlx_img);
	mlx_destroy_display(win.mlx_ptr);
	free(win.mlx_ptr);
	exit(EXIT_SUCCESS);
}

int	ft_close_window(t_win *win)
{
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	win->win_ptr = NULL;//implement for hook loop
	return (0);
}

int	ft_key(int key, t_win *win)
{
	if (key == 65307)
		ft_close_window(win);
	return (0);
}

