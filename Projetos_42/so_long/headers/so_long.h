/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:36:27 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/16 14:59:26 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "defines.h"
#include "libs.h"
#include "strutcs.h"

int		main(int argc, char **argv);
void	ft_check_input(int argc, char *str, t_sl *sl);
void	ft_create_string_map(int fd, t_sl *sl);
void	ft_chek_map(t_sl *sl);
void	ft_char1_map(t_sl *sl);
void	ft_char2_map(t_sl *sl);
void	ft_wall_map(t_sl *sl);
void	ft_init_win(t_sl *sl);
void	ft_error_input(int n_error);
void	ft_error_map(int n_error);
void	ft_error_win(int n_error);

#endif