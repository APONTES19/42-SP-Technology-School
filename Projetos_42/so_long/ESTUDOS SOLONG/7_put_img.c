/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_put_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:49:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/21 15:07:13 by lucasmar         ###   ########.fr       */
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
}	t_img;

typedef struct window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}			t_win;

int		close_window(t_win *win);
int		key_esc(int key, t_win *win);
void	pixel_put(t_win *win, int x, int y, int color);
int	render(t_win *win);

int	main(void)
{
	t_win	win;

	win.mlx_ptr = mlx_init();
	if (win.mlx_ptr == NULL)
		exit(EXIT_FAILURE);

	win.win_ptr = mlx_new_window(win.mlx_ptr, 400, 800, "My firt window");
	if (win.win_ptr == NULL)
	{
		free(win.win_ptr);
		exit(EXIT_FAILURE);
	}

	win.img.mlx_img = mlx_new_image(win.mlx_ptr, 400, 800);
	win.img.addr = mlx_get_data_addr(win.img.mlx_img,&win.img.bpp,
		&win.img.line_len, &win.img.endian);
	mlx_loop_hook(win.mlx_ptr, render, &win);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.img.mlx_img, 0, 0);

	mlx_hook(win.win_ptr, 33, 1L << 17, close_window, &win);
	mlx_key_hook(win.win_ptr, &key_esc, &win);

	mlx_loop(win.mlx_ptr);

	mlx_destroy_image(win.mlx_ptr, win.img.mlx_img);
	mlx_destroy_display(win.mlx_ptr);
	free(win.mlx_ptr);
	exit(EXIT_SUCCESS);
}

int	close_window(t_win *win)
{
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	win->win_ptr = NULL;//implement for hook loop
	return (0);
}

int	key_esc(int key, t_win *win)
{
	if (key == 65307)
		close_window(win);
	return (0);
}

void	pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->img.addr + (y * win->img.line_len + x * (win->img.bpp / 8));
	*(unsigned int*)dst = color;
}

int	render(t_win *win)
{
	int	i_x;
	int	i_y;
	int	s_x;
	int	s_y;
	int	x;
	int	y;


	i_x = 10;
	i_y = 10;
	s_x = 100;
	s_y = 100;

	y = i_y;
	while (y <= (i_y + s_y))
	{
		x = i_x;
		while(x <= (i_x + s_y))
		{
			pixel_put(win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
	return (0);
}

