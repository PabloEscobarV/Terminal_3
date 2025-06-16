/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:52:08 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/06/16 21:33:37 by Pablo Escob      ###   ########.fr       */
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

static void	wrong_file_fd(t_cchar *file_name)
{
	printf("%s: no such file or directory\n", file_name);
	exit(PE_NO_FILE);
}

static void	set_input_descriptor(const t_argv *argvt, int *pipefd)
{
	int	fd;
	
	if (pipefd && pipefd[0] < 0)
		return ;
	fd = -1;
	if (argvt->in_file)
	{
		fd = open(argvt->in_file, O_RDONLY);
		if (fd < 0)
			wrong_file_fd(argvt->in_file);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	if (pipefd && fd < 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
	}
	return ;
}

static void set_output_descriptor(const t_argv *argvt, int *pipefd)
{
	int	fd;
	
	fd = -1;
	if (argvt->out_file)
	{
		if (argvt->out_append)
			fd = open(argvt->out_file, O_WRONLY | O_CREAT | O_APPEND);
		else
			fd = open(argvt->out_file, O_WRONLY | O_CREAT);
		if (fd < 0)
			wrong_file_fd(argvt->out_file);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	if (fd < 0 && pipefd)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
	}
}

static void	exec_pipe(const t_argv *argvt, t_cchar **envp, int *pipefd)
{
	set_input_descriptor(argvt, pipefd);
	set_output_descriptor(argvt, pipefd);
	execve(argvt->app_path, (char* const*)(argvt->argv), (char* const*)envp);
	exit(-1);
}

int	pipex(const t_argv *argvt, t_cchar **envp, int *pipefd)
{
	int	pid;

	if (!argvt)
		return (E_ERR);
	pid = fork();
	if (pid < 0)
		return (E_ERR);
	if (!pid)
		exec_pipe(argvt, envp, pipefd);
	return (pid);
}

// static void	wrong_file_fd(t_cchar *file_name)
// {
// 	printf("%s: no such file or directory\n", file_name);
// 	exit(PE_NO_FILE);
// }

// static void	set_input_descriptor(t_argv *argvt, int in_pipe)
// {
// 	int	fd;
	
// 	if (argvt->in_file)
// 	{
// 		fd = open(argvt->in_file, O_RDONLY);
// 		if (fd < 0)
// 			wrong_file_fd(argvt->in_file);
// 		dup2(fd, STDIN_FILENO);
// 		close(in_pipe);
// 		close(fd);
// 		return ;
// 	}
// 	dup2(in_pipe, STDIN_FILENO);
// 	close(in_pipe);
// }

// static void set_output_descriptor(t_argv *argvt, int out_pipe)
// {
// 	int	fd;
	
// 	if (argvt->out_file)
// 	{
// 		if (argvt->out_append)
// 			fd = open(argvt->out_file, O_WRONLY | O_CREAT | O_APPEND);
// 		else
// 			fd = open(argvt->out_file, O_WRONLY | O_CREAT);
// 		if (fd < 0)
// 			wrong_file_fd(argvt->out_file);
// 		dup2(fd, STDOUT_FILENO);
// 		close(out_pipe);
// 		close(fd);
// 		return ;
// 	}
// 	dup2(out_pipe, STDOUT_FILENO);
// 	close(out_pipe);
// }