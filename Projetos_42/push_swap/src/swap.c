/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:18:37 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/09 08:29:22 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

void	ft_sa(t_ps *ps, char *mov)
{
	ft_swap(ps->stack_a, ps->size_sta, mov);
}

void	ft_sb(t_ps *ps, char *mov)
{
	ft_swap(ps->stack_b, ps-> size_stb, mov);
}

void	ft_ss(t_ps *ps, char *mov)
{
	ft_sa(ps, "void");
	ft_sb(ps, "void");
	ft_put_mov(mov);
}

void	ft_swap(int *stack, int size_st, char *mov)
{
	int	temp;

	temp = stack[0];
	if (size_st > 1)
	{
		stack[0] = stack[1];
		stack[1] = temp;
		ft_put_mov(mov);
	}
}
