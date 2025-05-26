/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:23:51 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/05/26 21:44:40 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"

#include "../../libft/libft.h"
#include "../../netdata/hdrs/netdata.h"
#include "../../get_app_path/hdrs/get_app_path.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <readline/readline.h>

static void	exec_pipe(t_cchar *app_path, t_cchar **argv, t_cchar **envp, int *pipefd)
{
	printf("ENTERD into EXECUTION\n");
	if (pipefd[0] > 2)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
	}
	if (pipefd[1] > 2)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
	}
	execve(app_path, (char* const*)argv, (char* const*)envp);
	ft_perror("ERROR!!!: execve");
	exit(-1);
}

int	parent_handler(int pid, int *pipefd)
{
	int	status;

	status = -1;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	close(pipefd[1]);
	return (status);
}

int	pipex(t_cchar *app_path, t_cchar **argv, t_cchar **envp, int *pipefd)
{
	int	pid;
	int	status;

	if (!argv || !(*argv))
		return (E_ERR);
	pid = fork();
	if (pid < 0)
		return (E_ERR);
	if (!pid)
		exec_pipe(app_path, argv, envp, pipefd);
	if (pid > 0)
		status = parent_handler(pid, pipefd);
	return (status);
}

int	main(int argc_m, char **argv_m, char **envp)
{
	static const int buffer_size = 64;
	char			buffer[64] = {0};
	int				pipefd[2] = {0};
	int				status;
	char			*app_path;
	char		 	**argv;

	while (1)
	{
		app_path = readline("Enter next command:\t");
		if (!ft_strcmp(app_path, "exit"))
			break ;
		argv = ft_split(app_path, ' ');
		free(app_path);
		app_path = get_app_path_envp((t_cchar *)argv[0], (t_cchar **)envp);
		printf("APP PATH:\t%s\n", app_path);
		pipe(pipefd);
		status = pipex((t_cchar *)app_path, (t_cchar **)argv, (t_cchar **)envp, pipefd);
		read(pipefd[0], buffer, buffer_size - 1);
		printf("%s", buffer);
		printf("EXIT STATUS:\t%d\n", status);
		free(app_path);
		ft_free_d((void **)argv);
		close(pipefd[0]);
	}
	free(app_path);
	return (0);
}

static void	print_in_data(t_cchar *app_path, t_cchar **argv)
{
	printf("APP PATH:\t%s\n", app_path);
	for (int i = 0; argv[i]; ++i)
		printf("arg[%d]:\t%s\n", i, argv[i]);
}
