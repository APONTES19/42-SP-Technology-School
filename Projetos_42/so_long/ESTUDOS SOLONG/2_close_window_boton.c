/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_close_window_boton.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:49:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/17 15:50:41 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <X11/X.h>

/*Compile with
clang 1_open_window.c -I ../libs/mlx -L ../libs/mlx -lmlx -Ilmlx -lXext -lX11
../libs/mlx/libmlx.a -O 2_close_window_boton*/

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_window;

int	close_window(t_window *win);

int	main(void)
{
	t_window	win;

	win.mlx_ptr = mlx_init();
	if (win.mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	win.win_ptr = mlx_new_window(win.mlx_ptr, 400, 800, "My firt window");
	if (win.win_ptr == NULL)
	{
		free(win.win_ptr);
		exit(EXIT_FAILURE);
	}
	mlx_hook(win.win_ptr, 33, 1L << 17, close_window, &win);
	mlx_loop(win.mlx_ptr);
	mlx_destroy_display(win.mlx_ptr);
	free(win.win_ptr);
	exit(EXIT_SUCCESS);
}

int	close_window(t_window *win)
{
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	return (0);
}
