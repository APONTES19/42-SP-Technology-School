/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutcs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:53:39 by lucasmar          #+#    #+#             */
/*   Updated: 2022/04/27 20:32:35 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUTCS_H
# define STRUTCS_H

typedef struct arg
{
	char	*infile;
	char	**cmd1;
	char	**cmd2;
	char	*outfile;
	int		infile_fd;
	int		outfile_fd;
}	t_arg;

typedef struct pipex
{
	char	**path_envp;
	char	*path_cmd1;
	char	*path_cmd2;
	int		pid_1;
	int		pid_2;
	int		pipe_fd[2];
	char	*aux_temp;
	int	i;
	int	a;
	t_arg	arg;
}	t_px;

#endif
