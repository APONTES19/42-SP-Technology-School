/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_open_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:49:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/17 15:51:56 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/mlx/mlx.h"
#include <stdlib.h>

/*Compile with
clang 1_open_window.c -I ../libs/mlx -L ../libs/mlx -lmlx -Ilmlx -lXext -lX11
../libs/mlx/libmlx.a -O 1_open_window*/

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_window;

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
	mlx_loop(win.mlx_ptr);
	return (0);
}
//we will exit the loop with ctrl+c
