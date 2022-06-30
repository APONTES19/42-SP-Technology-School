/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:37:26 by lucasmar          #+#    #+#             */
/*   Updated: 2022/06/30 16:14:16 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

int	main(int argc, char **argv)
{
	t_ps	ps;

	ft_memset(&ps, 0, sizeof ps);
	ft_check_input(argc, argv, &ps);
	return (0);
}

int	ft_check_input(int argc, char **stack, t_ps *ps)
{
	if(argc <= 1)
		ft_error_input(0);
	ps->x = 1;
	while (stack[ps->x])
	{
		ps->y = 0;
		while(stack[ps->x][ps->y])
		{
			if (!(ft_strrchr("+-0123456789", stack[ps->x][ps->y])))
				ft_error_input(1);
			ps->y++;
		}
		if(ft_strlen(stack[ps->x]) >= 10)
			ft_check_maxmin(stack[ps->x], ps);
		ps->x++;
	}
	ft_check_dup(stack, ps);
	return (0);
}

void	ft_error_input(int n_error)
{
		if (n_error == 1 || n_error == 2 )
			printf("error\n");
		exit(3);
}

void	ft_check_maxmin(char *stack, t_ps *ps)
{
	if (stack[0] == '-')
	{
		if (ft_strlen(stack) > 11)
			ft_error_input(2);
	}
	else if (ft_strlen(stack) > 10)
		ft_error_input(2);
	ps->num = ft_long_atoii(stack);
	printf("|%ld|\n",ps->num);
	if (ps->num >= 2147483647 || ps->num <= -2147483648)
		ft_error_input(2);
}

void	ft_check_dup(char **stack, t_ps *ps)
{
	ps->x = 1;
	while(stack[ps->x])
	{
		ps->y = 1;
		while(stack[ps->y])
		{
			if(ps->y != ps->x)
			{
				if(!(ft_strncmp(stack[ps->x], stack[ps->y], 11)))
					ft_error_input(2);
			}
			ps->y++;
		}
		ps->x++;
	}
}
