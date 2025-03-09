/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:27:48 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/09 15:45:55 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETDATA_H
#define NETDATA_H

#include "../../libft/libft.h"

# define ND_RSRVD_SYMB "\\|$<>\"\'"
# define ND_SPLITTERS	"|| $$ >> << < > |"
# define ND_SKIP_PAIR	"\" \'"
# define ND_ESC_CH		'\\'

typedef enum	e_operations
{
	E_OPER_OR,
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
	t_operations	operation;
	t_uchar				out_append;
	t_cchar				*app_path;
	t_cchar				*in_file;
	t_cchar				*out_file;
	t_cchar				**argv;
}								t_argv;

t_llist	*netdata(t_cchar *args, t_cchar **operations, t_cchar **data);

t_argv	*crt_argvt();
void	free_argvt(void *data);

#endif