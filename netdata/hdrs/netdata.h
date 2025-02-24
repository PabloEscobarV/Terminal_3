/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:27:48 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/24 21:39:52 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETDATA_H
#define NETDATA_H

# define ND_SPLITTERS	"|| $$ >> << < > |"
# define ND_SKIP_PAIR	"\" \'"
# define ND_ESC_CH		'\\'

typedef enum	e_operations
{	E_OPER_OR,
	E_OPER_AND,
	E_OPER_APP_OUTFILE,
	E_OPER_HERDOC,
	E_OPER_INFILE,
	E_OPER_OUTFILE,
	E_OPER_PIPE,
	E_OPER_SIZE
}							t_operations;

typedef struct	s_rsrvd
{
	char	*qts;
	char	*reserved;
	char	**operations;
}								t_rsrvd;

typedef struct	s_argv
{
	t_uchar				in_herdoc;
	t_uchar				out_append;
	char					*in_file;
	char					*out_file;
	char					*app_path;
	char					**argv;
	t_operations	operation;
}								t_argv;

#endif