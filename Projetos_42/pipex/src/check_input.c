/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:38:22 by lucasmar          #+#    #+#             */
/*   Updated: 2022/04/27 15:25:21 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int		ft_check_input (int argc, char **argv, char **envp, t_px *px)
{
	if (argc != 5)
		ft_error_arg(1);
	if (ft_check_files(px, argv, 'o') == -3)
		ft_error_arg(3);
	if (ft_check_files(px, argv, 't') == -2)
		ft_error_arg(2);
	ft_check_path(px, envp);
	if(ft_check_cmd1(px, argv) == -1)
		ft_error_arg(4);
	if(ft_check_cmd2(px, argv) == -1)
		ft_error_arg(5);
	ft_printf("\n	Arguments OK ✓\n\n");
	return (0);
}

int		ft_check_files(t_px *px, char **argv, char type)
{
	if (type == 't')
	{
		px->arg.infile = argv[1];
		px->arg.infile_fd = open(px->arg.infile, O_RDONLY);
		if (px->arg.infile_fd == -1)
			return (-2);
		ft_printf ("\n	Infile OK ✓\n");
	}
	if (type == 'o')
	{
		px->arg.outfile = argv[4];
		px->arg.outfile_fd = open(px->arg.outfile, \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (px->arg.outfile_fd == -1)
			return (-3);
		ft_printf ("	Outfile OK ✓\n");
	}
	return (0);
}

void	ft_check_path(t_px *px, char **envp)
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
		ft_error_arg(5);
	px->path_envp = ft_split(px->aux_temp, ':');
	px->aux_temp= NULL;
	px->i = 0;
	ft_printf ("	PATH OK ✓\n");
}

int		ft_check_cmd1(t_px *px, char **argv)
{
		px->arg.cmd1 = ft_split(argv[2],' ');
		px->aux_temp = ft_strjoin("/",px->arg.cmd1[0]);
		while(px->path_envp[px->i])
		{
			px->path_cmd1 = ft_strjoin(px->path_envp[px->i], px->aux_temp);
			px->a = access(px->path_cmd1, F_OK | X_OK);
			if (px->a == 0)
				break;
			free(px->path_cmd1);
			px->path_cmd1 = NULL;
			px->i++;
		}
		free(px->aux_temp);
		px->aux_temp = NULL;
		px->i = 0;
		if (px->a != 0)
			return(-1);
		ft_printf ("	Cmd1 OK ✓\n");
		return(0);
}

int		ft_check_cmd2(t_px *px, char **argv)
{
	px->arg.cmd2 = ft_split(argv[3], ' ');
	px->aux_temp = ft_strjoin("/",px->arg.cmd2[0]);
		while(px->path_envp[px->i])
	{
		px->path_cmd2 = ft_strjoin(px->path_envp[px->i], px->aux_temp);
		px->a = access(px->path_cmd2, F_OK | X_OK);
		if (px->a == 0)
			break;
		free(px->path_cmd2);
		px->path_cmd2 = NULL;
		px->i++;
	}
	free(px->aux_temp);
	px->aux_temp = NULL;
	if (px->a != 0)
		return(-1);
	ft_printf ("	Cmd2 OK ✓\n");
	return (0);
}
