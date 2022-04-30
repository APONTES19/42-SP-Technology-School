/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:38:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/04/30 15:40:17 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int		ft_check_input(int argc, char **argv, char **envp, t_px *px)
{
	if (px->pid_1 == -2)
	{
		if (argc != 5)
			ft_error_arg(px, 1, 189);
		if (ft_check_path(px, envp) == -1)
			ft_error_arg(px, 6, 188);
	}
	else if (px->pid_1 == 0 && px->pid_2 == -2)
	{
		if (ft_check_file(px, argv, 'i') == -2)
			ft_error_arg(px, 2, 0);
		printf("	3 - INFILE_FD: |%d| & |%p|\n",px->arg.infile_fd, &px->arg.infile_fd);
		if(ft_check_cmd(px, &argv[2], &px->arg.cmd1, &px->path_cmd1) == -1)
			ft_error_arg(px, 4, 0);
		printf("	5 - CMD1|%s| & |%p| PATH|%s| & |%p|\n", px->arg.cmd1[0], px->arg.cmd1[0], px->path_cmd1, px->path_cmd1);
	}
	else if (px->pid_2 == 0)
	{
		printf("PID1 : |%d & %p| e PID2 |%d & %p|\n", px->pid_1, &px->pid_1, px->pid_2, &px->pid_2);
		if (ft_check_file(px, argv, 'o') == -3)
			ft_error_arg(px, 3, 0);
		printf("	4 - OUTFILE_FD: |%d| & |%p|\n",px->arg.outfile_fd, &px->arg.outfile_fd);
		if(ft_check_cmd(px, &argv[3], &px->arg.cmd2, &px->path_cmd2) == -1)
			ft_error_arg(px, 5, 0);
		printf("	5 - CMD2|%s| & |%p| PATH|%s| & |%p|\n", px->arg.cmd2[0], px->arg.cmd2[0], px->path_cmd2, px->path_cmd2);
	}
	return (0);
}

int	ft_check_path(t_px *px, char **envp)
{
	while(envp[px->i])
	{
		if(ft_strnstr(envp[px->i], "PATH", 4))
		{
			px->aux_temp = ft_strchr(envp[px->i], '/');
			break;
		}
		px->i++;
	}

	if (px->aux_temp == 0)
		return (-1);
	px->path_envp = ft_split(px->aux_temp, ':');
	px->aux_temp= NULL;
	px->i = 0;
	return(0);
}

int		ft_check_file(t_px *px, char **argv, char type)
{
	if (type == 'i')
	{
		px->arg.infile = argv[1];
		px->arg.infile_fd = open(px->arg.infile, O_RDONLY);
		if (px->arg.infile_fd == -1)
			return (-2);
		printf("	3 - INFILE_FD: |%d| & |%p|\n",px->arg.infile_fd, &px->arg.infile_fd);
	}
	if (type == 'o')
	{
		px->arg.outfile = argv[4];
		px->arg.outfile_fd = open(px->arg.outfile, \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (px->arg.outfile_fd == -1)
			return (-3);
		write(px->arg.outfile_fd, "0\n", 2);
		printf("	4 - OUTFILE_FD: |%d| & |%p|\n",px->arg.outfile_fd, &px->arg.outfile_fd);
	}
	return (0);
}

int		ft_check_cmd(t_px *px, char **argv, char ***cmd, char **path_cmd)
{
	*cmd = ft_split(*argv, ' ');
	px->aux_temp = ft_strjoin("/",*cmd[0]);
	while(px->path_envp[px->i])
	{
		*path_cmd = ft_strjoin(px->path_envp[px->i], px->aux_temp);
		px->a = access(*path_cmd, F_OK | X_OK);
		if (px->a == 0)
			break;
		free(*path_cmd);
		*path_cmd = NULL;
		px->i++;
	}
	free(px->aux_temp);
	px->aux_temp = NULL;
	if (px->a != 0)
		return(-1);
	printf("	5 - CMD1|%s| & |%p| PATH|%s| & |%p|\n", *cmd[0], *cmd[0], *path_cmd, *path_cmd);
	return (0);
}
