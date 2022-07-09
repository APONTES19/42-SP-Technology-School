/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:37:19 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/08 21:28:58 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

void	ft_pa(t_ps *ps, char *mov)
{
	if (ps->size_stb > 0)
	{
		ft_memmove(&ps->stack_a[1], &ps->stack_a[0],
			(sizeof (int) * ps->size_sta));
		ps->stack_a[0] = ps->stack_b[0];
		ps->size_sta++;
		ps->size_stb--;
		ft_memmove(&ps->stack_b[0], &ps->stack_b[1],
			(sizeof (int) * ps->size_stb));
		ft_put_mov(mov);
	}
}

void	ft_pb(t_ps *ps, char *mov)
{
	if (ps->size_sta > 0)
	{
		ft_memmove(&ps->stack_b[1], &ps->stack_b[0],
			(sizeof (int) * ps->size_stb));
		ps->stack_b[0] = ps->stack_a[0];
		ps->size_stb++;
		ps->size_sta--;
		ft_memmove(&ps->stack_a[0], &ps->stack_a[1],
			(sizeof (int) * ps->size_sta));
		ft_put_mov(mov);
	}
}
