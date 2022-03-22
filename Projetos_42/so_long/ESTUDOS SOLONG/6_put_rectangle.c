/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_put_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:49:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/18 17:05:25 by lucasmar         ###   ########.fr       */
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

typedef struct rect
{
	int	s_x;
	int	s_y;
	int	i_x;
	int	i_y;
	int	color;
}	t_rec;

typedef struct window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_rec	rec;
}			t_win;

int	close_window(t_win *win);
int	key_esc(int key, t_win *win);
int	render (t_win *win);
int	render_1 (t_win *win);
int	put_rect(t_win *win);

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
	mlx_loop_hook(win.mlx_ptr, &render, &win);

	mlx_hook(win.win_ptr, 33, 1L << 17, close_window, &win);
	mlx_key_hook(win.win_ptr, &key_esc, &win);

	mlx_loop(win.mlx_ptr);

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

//this is code hex red 0xFF0000
int	render (t_win *win)
{
	if(win->win_ptr != NULL)
	{
		win->rec.color = 0xFEFEFE;
		win->rec.s_x = 200;
		win->rec.s_y = 200;
		win->rec.i_x = 0;
		win->rec.i_y = 0;

		put_rect(win);

		win->rec.color = 0xFEFEFE;
		win->rec.i_x = 200;
		win->rec.i_y = 200;

		put_rect(win);

		win->rec.color = 0xFEFEFE;
		win->rec.i_x = 0;
		win->rec.i_y = 400;

		put_rect(win);

		win->rec.color = 0xFEFEFE;
		win->rec.i_x = 200;
		win->rec.i_y = 600;

		put_rect(win);
	}
	return (0);
}

int	put_rect(t_win *win)
{
	int	x;
	int	y;

	y = win->rec.i_y;
	if (win->win_ptr == NULL)
		exit(EXIT_FAILURE);
	while(y <= (win->rec.i_y + win->rec.s_y))
	{
		x = win->rec.i_x;
		while(x <= (win->rec.i_x + win->rec.s_x))
		{
			mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, win->rec.color);
			x++;
		}
		y++;
	}
	return (0);
}
