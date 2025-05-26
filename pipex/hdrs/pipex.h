/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:23:59 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/05/26 21:42:02 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../../libft/libft.h"

typedef enum	e_pipex_error
{
	PE_FORK_ERROR = -4 ,
	PE_INFILE_OPEN_ERR,
	PE_OUTFILE_ERR,
	PE_OK,
}							t_pipex_error;

int	pipex(t_cchar *app_path, t_cchar **argv, t_cchar **envp, int *pipefd);

#endif