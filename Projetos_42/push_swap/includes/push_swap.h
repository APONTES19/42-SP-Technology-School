/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:38:27 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/09 18:39:43 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./define.h"
# include "./libs.h"
# include "./strutcs.h"

int		main(int argc, char **argv);
int		ft_check_input(int argc, char **stack, t_ps *ps);
long	ft_long_atoi(const char *str);
void	ft_check_maxmin(char *stack, t_ps *ps);
void	ft_creat_stack(int argc, char **stack, t_ps *ps);
void	ft_check_dup(t_ps *ps);
void	ft_error(int n_error, t_ps *ps);
void	ft_push_swap(t_ps *ps);
int		ft_check_order(t_ps *ps);
void	ft_put_mov(char *mov);
void	ft_sa(t_ps *ps, char *mov);
void	ft_sb(t_ps *ps, char *mov);
void	ft_ss(t_ps *ps, char *mov);
void	ft_swap(int *stack, int size_st, char *mov);
void	ft_pa(t_ps *ps, char *mov);
void	ft_pb(t_ps *ps, char *mov);
void	ft_ra(t_ps *ps, char *mov);
void	ft_rb(t_ps *ps, char *mov);
void	ft_rr(t_ps *ps, char *mov);
void	ft_rotation(int *stack, int size_st, char *mov);
void	ft_rra(t_ps *ps, char *mov);
void	ft_rrb(t_ps *ps, char *mov);
void	ft_rrr(t_ps *ps, char *mov);
void	ft_rotation_down(int *stack, int size_st, char *mov);
void	radix(t_ps *ps);
void	ft_swap_three(t_ps *ps);
void	ft_swap_five(t_ps *ps);
void	ft_smaller_int(t_ps *ps);
void	ft_swap_positive(t_ps *ps);
void	ft_end_free(t_ps *ps, int type);
#endif
