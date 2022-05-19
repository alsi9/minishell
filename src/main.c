/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:04:20 by ephantom          #+#    #+#             */
/*   Updated: 2022/03/30 19:13:48 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	my_sigint(int signal)
{
	if (signal == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		write(2, "  \n", 3);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_exit_status = 1;
	}
}

void	handler_sig(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, my_sigint);
	signal(SIGTSTP, SIG_IGN);
}

void	check_number_arg(int argc, char **argv)
{
	if (argc != 1)
	{
		ft_putstr_fd(GREEN ER_NAME": "END, 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": no such file or directory\n", 2);
		exit(127);
	}
}

void	init_struct(t_all *all)
{
	all->list_envp = NULL;
	all->path = NULL;
	all->fd_in = -1;
	all->fd_out = -1;
	all->fd_add_out = -1;
	all->here_doc = NULL;
	all->tmp_in = -1;
	all->pipe_fd_in = -1;
	all->pipe_fd_out = -1;
	all->arg_list = NULL;
	all->pipe_id = 0;
	all->pipe = 0;
	all->pipex = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_all	all;

	check_number_arg(argc, argv);
	handler_sig();
	init_struct(&all);
	if (envp_to_list(&all, envp) == 1)
		return (1);
	g_exit_status = 0;
	while (1)
	{
		handler_sig();
		str = readline(GREEN NAME"> "END);
		if (!str)
		{
			write(1, "exit\n", 5);
			break ;
		}
		if (str[0])
			add_history(str);
		parser(str, &all);
		free(str);
	}
	free_all(&all);
	return (0);
}
