/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:45:38 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/09 09:56:37 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

void	ft_error(int n_error, t_ps *ps)
{
	if (n_error == 1)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (n_error == 2)
	{
		ft_printf("Error\n");
		ft_end_free(ps, 2);
	}
	exit(EXIT_FAILURE);
}

void	ft_end_free(t_ps *ps, int type)
{
	free(ps->stack_a);
	free(ps->stack_b);
	ft_memset(&ps, 0, sizeof ps);
	if (type == 2)
		exit(EXIT_FAILURE);
}
