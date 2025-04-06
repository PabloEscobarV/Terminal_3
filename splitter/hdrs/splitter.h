/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:02:34 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/04/06 16:04:10 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITTER_H
# define SPLITTER_H

#include "../../libft/libft.h"

#define SPLT_QUETS	"\"\'"
#define SPLT_ESC_CH	'\\'
#define SPLT_SPACE	' '
#define SPLT_OPERATIONS	"||,$$,<<,>>,>,<,|,$,"
#define SPLT_SPLIT_OPER	','

typedef struct	s_args
{
	int				operation;
	t_cchar		*data;
}								t_args;

t_llist	*splitter(t_cchar *str, t_cchar **operation);
t_args	*crt_t_args(t_cchar *data, int operation);
void		free_t_args(void *data);

static inline t_args *get_args(t_llist *data)
{
	return ((t_args *)(data->data));
}

#endif