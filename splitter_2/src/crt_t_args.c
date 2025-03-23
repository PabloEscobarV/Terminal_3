/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crt_t_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:32:29 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/23 20:07:43 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"
#include "../hdrs/splitter_srvs.h"
#include "../../libft/libft.h"

t_args	*crt_t_args(t_cchar *data, int operation)
{
	t_args	*argst;

	argst = malloc(sizeof(t_args));
	if (!argst)
	{
		ft_perror("ERROR!!! Memory allocations");
		exit(-1);
	}
	argst->data = data;
	argst->operation = operation;
	return (argst);
}

void	free_t_args(void *data)
{
	free((void *)(((t_args *)data)->data));
	free(data);
}
