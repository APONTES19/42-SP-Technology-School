/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:38:11 by lucasmar          #+#    #+#             */
/*   Updated: 2022/04/30 15:48:06 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pipex.h>

void	ft_process(int argc, char **argv, char **envp, t_px *px)
{
	if ( pipe(px->pipe_fd) == -1)
		ft_error_process(2);

	if ((px->pid_1 = fork()) < 0)
		ft_error_process(1);


	if (px->pid_1 == 0)
	{
		printf("PID_1 PROCESSO FILHO [ INICIO ] \n");
		ft_check_input (argc, argv, envp, px);
		printf("\nFID PID: |%d||%d|\n",px->pipe_fd[0], px->pipe_fd[1]);
		ft_select_fd(px, 'i');
		printf("PID_1 PROCESSO FILHO [ FIM ] \n\n");
		execve(px->path_cmd1, px->arg.cmd1, px->path_envp);
	}
	else if (px->pid_1 > 0)
	{
		wait(&px->pid_1);
		printf("PID_1 PROCESSO PAI [ INICIO ] \n");
		printf("PID_1 PROCESSO PAI [ FIM ] \n\n");
		//if ((px->pid_2 = fork()) < 0)
		//	ft_error_process(3);
		close(px->pipe_fd[1]);
	}

	if (px->pid_2 == 0)
	{
		printf("PID_2 PROCESSO FILHO [ INICIO ] \n");
		ft_check_input (argc, argv, envp, px);
		//ft_select_fd(px, 'o');
		printf("PID_2 PROCESSO FILHO [ FIM ] \n\n");
		execve(px->path_cmd2, px->arg.cmd2, px->path_envp);
	}
	else if (px->pid_2 > 0)
	{
		wait(&px->pid_2);
		printf("PID_2 PROCESSO PAI [ INICIO ] \n");
		printf("PID_2 PROCESSO FILHO [ FIM ] \n\n");
		close(px->pipe_fd[0]);
	}


}

void	ft_select_fd (t_px *px, char type)
{
	if (type == 'i')
	{
		dup2(px->arg.infile_fd, 0);
		dup2(px->pipe_fd[1], 1);
		close(px->pipe_fd[1]);
		close(px->pipe_fd[0]);
		close(px->arg.infile_fd);
	}
	else if (type == 'o')
	{
		dup2(px->pipe_fd[0], STDIN_FILENO);
		dup2(px->arg.outfile_fd, 1);
		close(px->pipe_fd[1]);
		close(px->pipe_fd[0]);
		close(px->arg.outfile_fd);
	}
	}
