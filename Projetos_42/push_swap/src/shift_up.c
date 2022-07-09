/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:52:44 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/09 18:27:07 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

void	ft_ra(t_ps *ps, char *mov)
{
	ft_rotation(ps->stack_a, ps->size_sta, mov);
}

void	ft_rb(t_ps *ps, char *mov)
{
	ft_rotation(ps->stack_b, ps->size_stb, mov);
}

void	ft_rr(t_ps *ps, char *mov)
{
	ft_ra(ps, "void");
	ft_rb(ps, "void");
	ft_put_mov(mov);
}

void	ft_rotation(int *stack, int size_st, char *mov)
{
	int	temp;

	if (size_st > 1)
	{
		temp = stack[0];
		ft_memmove(&stack[0], &stack[1], sizeof (int) * (size_st -1));
		stack[size_st -1] = temp;
		ft_put_mov(mov);
	}
}
