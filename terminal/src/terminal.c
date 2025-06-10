/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:14:16 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/06/10 22:50:00 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/terminal.h"

#include "../../netdata/hdrs/netdata.h"
#include "../../str_handler/hdrs/str_handler.h"
#include "../../libft/libft.h"
#include "../hdrs/pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>

void	command_execute(int operation, int exit_status)
{
	switch (operation)
	{
		case E_OPER_OR:
			
			break;
		case E_OPER_AND:

			break ;
		case E_OPER_EXIT_CODE:

			break ;
		case E_OPER_HERDOC:

			break ;
		case E_OPER_APP_OUTFILE:

			break ;
		case E_OPER_OUTFILE:

			break ;
		case E_OPER_INFILE:

			break ;
		case E_OPER_PIPE:

			break ;
		default:
			break;
	}
}

int**	create_pipes(int pipe_count)
{
	int	**pipes;

	if (pipe_count < 1)
		return (NULL);
	pipes = malloc((pipe_count + 1) * sizeof(int *));
	if (!pipes)
	{
		ft_perror("ERROR!!! MALLOC: Try to create pipe");
		exit(-1);
	}
	pipes[pipe_count] = NULL;
	while (pipe_count)
	{
		--pipe_count;
		pipes[pipe_count] = malloc(2 * sizeof(int));
		if (!pipes[pipe_count])
		{
			ft_perror("ERROR!!! MALLOC: Try to create pipe");
			exit(-1);
		}
		if (pipe(pipe_count) < 0)
		{
			ft_perror("ERROR!!! in atemt to open pipe");
			return (NULL);
		}
	}
	return (pipes);
}

static void	wrong_file_fd(t_cchar *file_name)
{
	printf("%s: no such file or directory\n", file_name);
	exit(PE_NO_FILE);
}

static int	set_input_descriptor(t_argv *argvt, int *pipefd)
{
	int	fd;
	
	if (argvt->in_file)
	{
		fd = open(argvt->in_file, O_RDONLY);
		if (fd < 0)
		{
			wrong_file_fd(argvt->in_file);
			return (E_ERR);
		}
		close(pipefd[0]);
		pipefd[0] = fd;
	}
	return (0)
}

static int set_output_descriptor(t_argv *argvt, int *pipefd)
{
	int	fd;
	
	if (out_file)
	{
		if (out_append)
			fd = open(out_file, O_WRONLY | O_CREAT | O_APPEND);
		else
			fd = open(out_file, O_WRONLY | O_CREAT);
		if (fd < 0)
		{
			wrong_file_fd(out_file);
			return (E_ERR);
		}
		close(pipefd[1]);
		pipefd[1] = fd;
	}
	return (0);
}

void	fork_process(t_llist *argvll)
{
	int	i;
	int	pipe_count;
	int	pipefd[2];
	int **pipes;

	pipe_count = llistsize(argvll - 1);
	pipes = create_pipes(pipe_count);
	if (argvll->previous)
	{
		if (!argvll->previous->next)
		{
			close(pipes[i][0]);
			if (get_argv(argvll)->in_file)
				dup2
			else
				pipes[0][0] = PE_NO_INFILE;
		}
		if (!argvll->previous->next && !get_argv(argvll->previous)->out_file)
		{
			close(pipes[pipe_count][1]);
			pipes[pipe_count][1] = PE_NO_OUTFILE;
		}
	}

	i = 0;
	while (argvll)
	{

		argvll = argvll->next;
		++i;
	}
}

static inline int	pipex_runner(t_argv *argvt, t_cchar **envp, int *pipefd)
{
	return (pipex(argvt->app_path, argvt->argv, envp, pipefd));
}

int	argv_llist_handler(t_llist *argvll, t_cchar	**envp)
{
	int	exit_status;
	int	pipefd[2];

	set_pipefd(&pipefd, argvll->data);
	exit_status = pipex_runner(argvll->data, envp, &pipefd);
	argvll = argvll->next;
	while (argvll)
	{

		argvll = argvll->next;
	}
	return (exit_status);
}

static t_cchar	*read_data_with_promt()
{
	char	*str;

	*str = readline(TERMINAL_PROMT);
	if (!ft_strcmp(*str, TERMINAL_EXIT))
	{
		free(str);
		str = NULL;
	}
	return ((t_cchar *)str);
}

void	terminal()
{
	t_cchar	*data;
	t_cchar	**operations;
	t_hashtable *hashtable;
	t_llist	*argvt_llist;

	operations = (t_cchar **)ft_split(ND_OPERATIONS, ' ');
	hashtable = crthashtable(16);
	while (E_TRUE)
	{
		data = read_data_with_promt();
		if (!data)
			break ;
		argvt_llist = str_handler(data, operations, hashtable);

		llistclear(&argvt_llist, free_argvt);
		free(data);
	}
}

int	main()
{

	return (0);
}