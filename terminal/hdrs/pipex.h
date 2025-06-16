/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:52:37 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/06/16 21:33:34 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../../libft/libft.h"

typedef enum	e_pipex_error
{
	PE_NO_PIPE = -1,
	PE_OK,
	PE_NO_FILE
}							t_pipex_error;

int	pipex(const t_argv *argvt, t_cchar **envp, int *pipefd);

#endif