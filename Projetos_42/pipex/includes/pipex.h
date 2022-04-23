/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:49:04 by lucasmar          #+#    #+#             */
/*   Updated: 2022/04/23 01:22:14 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./strutcs.h"
# include "./libs.h"

int		main (int argc, char **argv, char **envp);
int		ft_check_input(int argc,char **argv, char **envp, t_px *px);
void	ft_error_arg(int n);
int		ft_check_files(t_px *px, char **argv, char type);
int		ft_check_cmd1(t_px *px, char **argv);
int		ft_check_cmd2(t_px *px, char **argv);
void	ft_check_path(t_px *px, char **envp);

int		teste(void);
#endif
