/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crt_argvt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:44:14 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/06 21:04:10 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../libft/libft.h"
#include <stdlib.h>

static t_argv	*_crt_argvt()
{
	t_argv	*argvt;

	argvt = malloc(sizeof(t_argv));
	if (!argvt)
	{
		ft_perror("ERROR of allocation t_argv");
		exit(-1);
	}
	return (argvt);
}

t_argv	*crt_argvt()
{
	t_argv	*argvt;

	argvt = _crt_argvt();
	argvt->app_path = NULL;
	argvt->argv = NULL;
	argvt->in_file = NULL;
	argvt->in_herdoc = 0;
	argvt->operation = E_OPER_SIZE;
	argvt->out_append = 0;
	argvt->out_file = NULL;
	return (argvt);
}

void	free_argvt(void *data)
{
	t_argv	*argvt;

	argvt = (t_argv *)data;
	ft_free_d((void **)argvt->argv);
	free((void *)argvt->in_file);
	free((void *)argvt->out_file);
	free((void *)argvt->app_path);
	free(argvt);
}
