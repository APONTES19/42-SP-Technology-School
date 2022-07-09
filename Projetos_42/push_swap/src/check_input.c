/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:18:47 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/09 18:25:58 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

int	ft_check_input(int argc, char **stack, t_ps *ps)
{
	if (argc <= 2)
		ft_error(0, ps);
	ps->x = 1;
	while (stack[ps->x])
	{
		ps->y = 0;
		while (stack[ps->x][ps->y])
		{
			if (!(ft_strrchr("+-0123456789", stack[ps->x][ps->y])))
				ft_error(1, ps);
			ps->y++;
		}
		if (ft_strlen(stack[ps->x]) >= 10)
			ft_check_maxmin(stack[ps->x], ps);
		ps->x++;
	}
	return (0);
}

void	ft_check_maxmin(char *stack, t_ps *ps)
{
	ps->lnum = ft_long_atoi(stack);
	if (ps->lnum > 2147483647 || ps->lnum < -2147483648)
		ft_error(1, ps);
}

void	ft_creat_stack(int argc, char **stack, t_ps *ps)
{
	ps->size = (argc - 1);
	ps->stack_a = malloc(sizeof(int) * (ps->size));
	ps->stack_b = malloc(sizeof(int) * (ps->size));
	if (!ps->stack_a || !ps->stack_b)
		ft_error(0, ps);
	ps->size_sta = ps->size;
	ps->size_stb = 0;
	ps->x = 1;
	ps->y = 0;
	while (stack[ps->x])
	{
		ps->inum = ft_atoi(stack[ps->x]);
		ps->stack_a[ps->y] = ps->inum;
		ps->x++;
		ps->y++;
	}
}

void	ft_check_dup(t_ps *ps)
{
	ps->x = 0;
	while (ps->x < ps->size_sta)
	{
		ps->y = 0;
		while (ps->y < ps->size_sta)
		{
			if (ps->y != ps->x)
			{
				if (ps->stack_a[ps->x] == ps->stack_a[ps->y])
					ft_error(2, ps);
			}
			ps->y++;
		}
		ps->x++;
	}
}
