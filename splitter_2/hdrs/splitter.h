/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:02:34 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/18 20:05:24 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITTER_H
# define SPLITTER_H

#include "../../libft/libft.h"

#define SPLT_QUETS	"\"\'"
#define SPLT_ESC_CH	'\\'

typedef struct	s_args
{
	t_uchar	operation;
	char		**data;
}								t_args;

char				**splitter(t_cchar *str, t_cchar **operation);

#endif