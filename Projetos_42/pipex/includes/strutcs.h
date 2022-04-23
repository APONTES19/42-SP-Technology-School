/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutcs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:53:39 by lucasmar          #+#    #+#             */
/*   Updated: 2022/04/23 00:56:37 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUTCS_H
# define STRUTCS_H

typedef struct arg
{
	char	*infile;
	char	*cmd1;
	char	*cmd2;
	char	*outfile;
	int		infile_fd;
	int		outfile_fd;
}	t_arg;

typedef struct pipex
{
	char	**path_envp;
	char	*aux_temp;
	int	i;
	int	a;
	t_arg	arg;
}	t_px;

#endif
