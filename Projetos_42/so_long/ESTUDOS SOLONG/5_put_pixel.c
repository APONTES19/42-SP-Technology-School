/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_put_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:49:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/18 11:40:24 by lucasmar         ###   ########.fr       */
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

typedef struct window
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_win;

int	close_window(t_win *win);
int	key_esc(int key, t_win *win);
int	render_pixel (t_win *win);

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
	mlx_loop_hook(win.mlx_ptr, &render_pixel, &win);

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
int	render_pixel (t_win *win)
{
	if (win->win_ptr != NULL)
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, 200, 400,0xFF0000);
	return (0);
}
