/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 07:56:09 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/09 18:24:44 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_five(t_ps *ps)
{
	while (ps->size_sta != 3)
	{
		ps->x = 0;
		ps->y = 1;
		while (ps->x < ps->size_sta)
		{
			if (ps->stack_a[0] > ps->stack_a[ps->x])
				ps->y++;
			ps->x++;
		}
		if (ps->y == 1)
			ft_pb(ps, "pb");
		else
			ft_ra(ps, "ra");
	}
	if (ps->size_stb > 2)
	{
		if (ps->stack_b[0] < ps->stack_b[1])
			ft_sb(ps, "sb");
	}
	ft_swap_three(ps);
	while (ps->size_stb != 0)
	{
		ft_pa(ps, "pa");
	}
}

void	ft_swap_three(t_ps *ps)
{
	while (!ft_check_order(ps) && ps->size_sta <= 3)
	{
		if (ps->stack_a[0] > ps->stack_a[1])
			ft_sa(ps, "sa");
		if (!ft_check_order(ps))
			ft_rra(ps, "rra");
	}
}

void	radix(t_ps *ps)
{
	ft_smaller_int(ps);
	if (ps->smaller < 0)
		ft_swap_positive(ps);
	ps->x = 0;
	while (!ft_check_order(ps))
	{
		ps->y = 0;
		while ((ps->y < ps->size_sta + ps->size_stb) && !ft_check_order(ps))
		{
			if ((ps->stack_a[0] >> ps->x) & 1)
				ft_ra(ps, "ra");
			else
				ft_pb(ps, "pb");
			ps->y ++;
		}
		ps->x ++;
		while (ps->size_stb > 0)
			ft_pa(ps, "pa");
	}
}

void	ft_swap_positive(t_ps *ps)
{
	ps->smaller *= (-1);
	ps->x = 0;
	while (ps->x < ps->size_sta)
	{
		ps->stack_a[ps->x] += ps->smaller;
		ps->x++;
	}
}

void	ft_smaller_int(t_ps *ps)
{
	ps->x = 0;
	ps->smaller = ps->stack_a[ps->x];
	while (ps->x < ps->size_sta)
	{
		if (ps->stack_a[ps->x] < ps->smaller)
			ps->smaller = ps->stack_a[ps->x];
		ps->x++;
	}
}
