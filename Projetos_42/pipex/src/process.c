/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:38:11 by lucasmar          #+#    #+#             */
/*   Updated: 2022/04/27 21:16:53 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pipex.h>

void	ft_fork(t_px *px)
{
	if ( pipe(px->pipe_fd) == -1)
		ft_error_process(2);
	if ((px->pid_1 = fork()) < 0)
		ft_error_process(1);
	if (px->pid_1 == 0)
	{
		printf("\n\nPROCESSO FILHO PID_1\n");
		ft_select_fd (px->arg.infile_fd, px, 0, 1);
		execve(px->path_cmd1, px->arg.cmd1, px->path_envp);
	}
	else if (px->pid_1 > 0)
	{
		if ((px->pid_2 = fork()) < 0)
			ft_error_process(3);
		wait(&px->pid_1);
		close(px->pipe_fd[1]);
	}
	if (px->pid_2 == 0)
	{
		printf("\n\nPROCESSO FILHO PID_2\n");
		ft_select_fd (px->arg.outfile_fd, px, 1, 0);
		execve(px->path_cmd2, px->arg.cmd2, px->path_envp);
	}
	else if (px->pid_2 > 0)
	{
		wait(&px->pid_2);
		close(px->pipe_fd[0]);
	}
}

void	ft_select_fd (int file_fd, t_px *px , int a, int b)
{
		printf("\nfile_fd = |%d|\n",file_fd);
		dup2(px->pipe_fd[b], b);//saida terminal para o pipe
		dup2(file_fd, a);//arquivo
		close(px->pipe_fd[1]);
		close(px->pipe_fd[0]);
		close(file_fd);
}
