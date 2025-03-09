/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_spliiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:22:20 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/09 15:43:27 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"
#include "../../libft/libft.h"
#include <stdlib.h>

t_splitter	*crt_splitter(t_cchar **split_ch, t_cchar **skip_pair, t_cchar esc)
{
	t_splitter	*splitter;

	splitter = malloc(sizeof(t_splitter));
	if (!splitter)
	{
		ft_perror("ERROR!!! Bad memmory alocation\n");
		exit(-1);
	}
	splitter->ecs_split = esc;
	splitter->splt = split_ch;
	splitter->skip_pair = skip_pair;
	return (splitter);
}

void	free_splitter(void *data)
{
	ft_free_d((void **)(((t_splitter *)data)->skip_pair));
	ft_free_d((void **)(((t_splitter *)data)->splt));
	free(data);
}
