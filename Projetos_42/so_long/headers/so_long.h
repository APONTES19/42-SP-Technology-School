/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:36:27 by lucasmar          #+#    #+#             */
/*   Updated: 2022/03/23 15:19:16 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./define.h"
# include "./libs.h"
# include "./strutcs.h"

int		main(int argc, char **argv);
void	ft_check_input(int argc, char *str, t_sl *sl);
void	ft_create_string_map(t_sl *sl);
void	ft_move_if_1(t_sl *sl);
void	ft_chek_map(t_sl *sl);
void	ft_count_char_map(t_sl *sl);
void	ft_valid_char_map(t_sl *sl);
void	ft_valid_wall_map(t_sl *sl);
void	ft_init_win(t_sl *sl);
int		ft_close_window(t_sl *sl);
int		ft_render(t_sl *sl);
void	ft_put_render(t_sl *sl, t_sl *img);
void	ft_set_img(t_sl *sl);
void	ft_print_steps(t_sl *sl);
int		ft_key(int key, t_sl *sl);
void	ft_move_left(t_sl *sl);
void	ft_move_rigth(t_sl *sl);
void	ft_move_up(t_sl *sl);
void	ft_move_down(t_sl *sl);
int		ft_next_move(t_sl *sl);
void	ft_move(t_sl *sl);
void	ft_check_p(t_sl *sl);
void	ft_error_input(t_sl *sl, int n_error);
void	ft_error_map(t_sl *sl, int n_error);
void	ft_error_win(t_sl *sl, int n_error);

#endif
