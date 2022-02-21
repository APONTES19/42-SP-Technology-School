/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_abrir_tela.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:49:23 by lucasmar          #+#    #+#             */
/*   Updated: 2022/01/24 14:15:15 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

typedef struct window
{
	void	*mlx_ptr;
	void	*win;
}			t_struct;

int	main(void)
{
	t_struct	window;
	
	window.mlx_ptr = mlx_init();
	window.win = mlx_new_window(window.mlx_ptr, 400, 800, "My firt window");
	mlx_loop(window.mlx_ptr);
}
