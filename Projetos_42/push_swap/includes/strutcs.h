/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutcs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:50:01 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/09 18:38:02 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUTCS_H
# define STRUTCS_H

typedef struct s_push_swap
{
	int		*stack_a;
	int		*stack_b;
	long	lnum;
	int		size;
	int		inum;
	int		x;
	int		y;
	int		a;
	int		b;
	int		size_sta;
	int		size_stb;
	int		smaller;
}	t_ps;

#endif
