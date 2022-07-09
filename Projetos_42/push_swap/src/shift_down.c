/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:54:28 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/09 18:08:09 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

void	ft_rra(t_ps *ps, char *mov)
{
	ft_rotation_down(ps->stack_a, ps->size_sta, mov);
}

void	ft_rrb(t_ps *ps, char *mov)
{
	ft_rotation_down(ps->stack_b, ps->size_stb, mov);
}

void	ft_rrr(t_ps *ps, char *mov)
{
	ft_rra(ps, "void");
	ft_rrb(ps, "void");
	ft_put_mov(mov);
}

void	ft_rotation_down(int *stack, int size_st, char *mov)
{
	int	temp;

	temp = stack[size_st -1];
	if (size_st > 1)
	{
		ft_memmove(&stack[1], &stack[0], sizeof (int) * (size_st -1));
		stack[0] = temp;
		ft_put_mov(mov);
	}
}
