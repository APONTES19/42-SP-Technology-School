int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	ft_init_data(argc, argv, envp, &data);
	##########################################
			void	ft_init_data(int arg_c, char **arg_v, char **env_p, t_data *data)
		{
			data->arg_c = arg_c;
			data->arg_v = arg_v;
			data->env_p = env_p;
			data->infile.name = data->arg_v[1];
			data->infile.file_ok = TRUE;
			data->cmd.str = data->arg_v[2];
			data->outfile.name = data->arg_v[4];
			data->cmd.args = NULL;
			data->cmd.path = NULL;
			data->exit_status = 0;
		}
	##########################################

	ft_init_pipex(&data);
	##########################################
		void	ft_init_pipex(t_data *data)
		{
			ft_check_argc(data);
				##########################################
					void	ft_check_argc(t_data *data)
					{
						if (data->arg_c != 5)
						{
							write(STDOUT_FILENO, ARGC_ERR, 37);
							exit (1);
						}
					}
				##########################################
			if (pipe(data->fd) == -1)
			//abril um pipe
				exit(1);
		}
	##########################################
	data.pid1 = fork();
	ft_check_fork(data.pid1);
	##########################################
		void	ft_check_fork(int pid)
		{
			if (pid == -1)
			{
				perror("fork");
				exit (2);
			}
		}
	##########################################
	ft_fork_one(&data);
	##########################################
		void	ft_fork_one(t_data *data)
		{
			if (data->pid1 == 0)
			{
				ft_check_infile(&data->infile);
					##########################################
						void	ft_check_infile(t_file *infile)
						{
							infile->fd = open(infile->name, O_RDONLY);
							if (infile->fd == -1)
							{
								infile->file_ok = FALSE;
								perror(infile->name);
								exit(1);
							}
						}
					##########################################
				ft_gen_cmd_args(data);
					##########################################
						void	ft_gen_cmd_args(t_data *data)
						{
							t_token	token;

							token.flag = FALSE;
							token.start = ft_strchr(data->cmd.str, '\'');
							if (token.start)
							{
								token.end = ft_strrchr(data->cmd.str, '\'');
								if (token.start != token.end && token.start[1] != token.end[0])
								{
									token.str = ft_substr(token.start, 1, \
									(token.end - token.start) - 1);
									ft_memset(token.start + 1, '%', (token.end - token.start) - 1);
									token.flag = TRUE;
								}
							}
							data->cmd.args = ft_split(data->cmd.str, ' ');
							if (!data->cmd.args)
							{
								write(STDOUT_FILENO, "Erro: command string generation!\n", 33);
								exit (3);
							}
							if (token.flag)
								ft_token(data, &token);
								##########################################
									void	ft_token(t_data *data, t_token *token)
									{
										int		i;
										char	*temp;

										i = 0;
										while (data->cmd.args[i][1] != '%')
											i++;
										temp = data->cmd.args[i];
										data->cmd.args[i] = token->start;
										free(temp);
									}
								##########################################
						}
					##########################################
				ft_start_pipex(data);
					##########################################
						void	ft_start_pipex(t_data *data)
						{
							ft_find_path(data);
							##########################################
								void	ft_find_path(t_data *data)
								{
									char	**arr;
									char	*path;
									char	*cmd;
									int		i;

									i = -1;
									path = ft_search_path(data->env_p);
									##########################################
										static char	*ft_search_path(char **env_p)
										{
											int		i;
											char	*path;

											i = 0;
											while (env_p[i++])
											{
												if (ft_strnstr(env_p[i], "PATH", 4))
													break ;
											}
											path = ft_strchr(env_p[i], '=') + 1;
											return (path);
										}
									##########################################

									arr = ft_split(path, ':');
									cmd = ft_strjoin('/', data->cmd.args[0]);
									while (arr[++i])
									{
										data->cmd.path = ft_strjoin(arr[i], cmd);
										if (data->cmd.path && !access(data->cmd.path, F_OK | X_OK))
										{
											ft_free_path(&arr, &cmd);
											##########################################
												void	ft_free_path(char ***arr, char **cmd)
												{
													ft_free_mtx(arr);
													##########################################
														void	ft_free_mtx(char ***mtx)
														{
															int	i;

															i = 0;
															while ((*mtx)[i])
															{
																free((*mtx)[i]);
																i++;
															}
															free(*mtx);
														}
													##########################################
													free(*cmd);
												}
												return ;
											##########################################
										}
										else
										{
											free(data->cmd.path);
											data->cmd.path = NULL;
										}
									}
									ft_free_path(&arr, &cmd);
									##########################################
										void	ft_free_path(char ***arr, char **cmd)
										{
											ft_free_mtx(arr);
											##########################################
												void	ft_free_mtx(char ***mtx)
												{
													int	i;

													i = 0;
													while ((*mtx)[i])
													{
														free((*mtx)[i]);
														i++;
													}
													free(*mtx);
												}
											##########################################
											free(*cmd);
										}
										return ;
									##########################################
									printf("->|%s|<-",data->cmd.path);
								}

							##########################################
							dup2(data->infile.fd, 0);
							dup2(data->fd[WRITE], 1);
							close(data->fd[WRITE]);
							close(data->fd[READ]);
							close(data->infile.fd);
						}
					##########################################
				ft_exec_cmd(data);
					##########################################
						void	ft_exec_cmd(t_data *data)
						{
							if (!data->infile.file_ok)
							{
								write(1, "\0", 1);
								return ;
							}
							if (!data->cmd.path || execve(data->cmd.path, data->cmd.args, data->env_p) == -1)
							{
								ft_putstr_fd(data->cmd.args[0], STDERR_FILENO);
								ft_putstr_fd(": command not found\n", STDERR_FILENO);
								ft_clean_data(data);
								exit(127);
							}
						}
					##########################################
			}
		}
	##########################################
	if (data.pid1 != 0)
	{
		data.pid2 = fork();
		ft_check_fork(data.pid1);
		##########################################
		##########################################
	}
	ft_fork_two(&data);
	if (data.pid1 != 0)
	{
		waitpid(data.pid1, &data.exit_status, WNOHANG);
		close(data.fd[WRITE]);
	}
	if (data.pid2 != 0)
	{
		waitpid(data.pid2, &data.exit_status, 0);
		close(data.fd[READ]);
	}
	printf("->|%s|<-",data.cmd.path);
	return (WEXITSTATUS(data.exit_status));
}
