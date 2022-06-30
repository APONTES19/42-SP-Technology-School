/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:38:27 by lucasmar          #+#    #+#             */
/*   Updated: 2022/06/30 16:00:17 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./define.h"
# include "./libs.h"
# include "./strutcs.h"

int	main(int argc, char **argv);
int	ft_check_input(int argc, char **stack, t_ps *ps);
void	ft_error_input(int n_error);
void	ft_check_maxmin(char *stack, t_ps *ps);
void	ft_check_dup(char **stack, t_ps *ps);
long	ft_long_atoii(const char *str);


#endif
