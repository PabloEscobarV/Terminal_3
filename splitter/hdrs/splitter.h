/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:02:34 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/09 15:40:36 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITTER_H
# define SPLITTER_H

#include "../../libft/libft.h"

typedef struct	s_splitter
{
	char		ecs_split;
	t_cchar	**splt;
	t_cchar	**skip_pair;
}								t_splitter;

char				**splitter(t_cchar *str, t_splitter *splitters);
t_splitter	*crt_splitter(t_cchar **split_ch, t_cchar **skip_pair, t_cchar esc);
void				free_splitter(void *data);

#endif