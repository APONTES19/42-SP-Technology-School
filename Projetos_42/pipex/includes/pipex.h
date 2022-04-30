/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:49:04 by lucasmar          #+#    #+#             */
/*   Updated: 2022/04/30 15:00:18 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./strutcs.h"
# include "./libs.h"

int		main (int argc, char **argv, char **envp);
int		ft_check_input (int argc, char **argv, char **envp, t_px *px);
int		ft_check_file (t_px *px, char **argv, char type);
int		ft_check_path (t_px *px, char **envp);
int		ft_check_cmd (t_px *px, char **argv, char ***cmd, char **path_cmd);
void	ft_process(int argc, char **argv, char **envp, t_px *px);
void	ft_select_fd (t_px *px, char type);
void	ft_zero_leak (t_px *px, int n);
void	ft_select_exit(int n);
void	ft_error_process(int n);
void	ft_error_arg(t_px *px, int n, int exit);
#endif
