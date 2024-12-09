/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:27:48 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/12/09 23:36:34 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETDATA_H
#define NETDATA_H

typedef enum	e_operations
{
	OR,
	PIPE,
	AND
}							t_operations;

typedef struct	s_argv
{
	char					*argv;
	char					*path;
	t_operations	operation;
}								t_argv;

#endif