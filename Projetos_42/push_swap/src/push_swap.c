/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:37:26 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/09 18:27:35 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

int	main(int argc, char **argv)
{
	t_ps	ps;

	ft_memset(&ps, 0, sizeof ps);
	ft_check_input(argc, argv, &ps);
	ft_creat_stack(argc, argv, &ps);
	ft_check_dup(&ps);
	if (!ft_check_order(&ps))
		ft_push_swap(&ps);
	ft_end_free(&ps, 0);
	return (0);
}

void	ft_push_swap(t_ps *ps)
{
	if (ps->size_sta <= 3)
		ft_swap_three(ps);
	else if (ps->size_sta <= 5)
		ft_swap_five(ps);
	else if (ps->size_sta > 6)
		radix(ps);
}

void	ft_put_mov(char *mov)
{
	if (ft_strncmp(mov, "void", 4))
		ft_printf("%s\n", mov);
}

int	ft_check_order(t_ps *ps)
{
	ps->b = (ps->size_sta -1);
	ps->a = 0;
	while (ps->b)
	{
		if (ps->stack_a[ps->a] > ps->stack_a[ps->a + 1])
			return (0);
		ps->b--;
		ps->a++;
	}
	return (1);
}
