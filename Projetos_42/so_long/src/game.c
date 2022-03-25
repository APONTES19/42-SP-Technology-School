/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:33:44 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/23 15:52:09 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	ft_key(int key, t_sl *sl)
{
	ft_printf("TECLA: %d \n", key);
	if (key == 65307)
		ft_close_window(sl);
	if (key == D_A || key == D_L)
	{
		ft_printf("VAMOS PRA ESQUERDA P ! \n", key);
		sl->map.str[sl->map.yp][sl->map.xp] = 0;
		sl->map.xp -= 1;
		sl->map.str[sl->map.yp][sl->map.xp] = 'P';
		ft_render(sl);
	}
	return (0);
}

//void	move(t_sl *sl)
//{
	// a esquerda
	// d direita
	// w cima
	// s baixo

	//if (a,d w,s)
//}
