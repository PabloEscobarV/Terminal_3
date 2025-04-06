/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:27:48 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/04/06 16:04:29 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETDATA_H
#define NETDATA_H

#include "../../libft/libft.h"
#include "../../splitter/hdrs/splitter.h"

# define ND_RSRVD_SYMB "\\|$<>\"\'"
# define ND_SPLITTERS	"|| $$ | $"
# define ND_OPERATIONS	"|| $$ << >> > < | $ "
# define ND_SKIP_PAIR	"\" \'"
# define ND_ESC_CH		'\\'
# define ND_SPACE			' '

typedef enum	e_operations
{
	E_OPER_NV = -2,
	E_OPER_ERR,
	E_OPER_OR,
	E_OPER_AND,
	E_OPER_HERDOC,
	E_OPER_APP_OUTFILE,
	E_OPER_OUTFILE,
	E_OPER_INFILE,
	E_OPER_PIPE,
	E_OPER_EXIT_CODE,
	E_OPER_SIZE
}							t_operations;

typedef struct	s_argv
{
	t_uchar				in_herdoc;
	int						operation;
	t_uchar				out_append;
	t_cchar				*app_path;
	t_cchar				*in_file;
	t_cchar				*out_file;
	t_cchar				**argv;
}								t_argv;

t_llist	*netdata(t_llist *data);

t_argv	*crt_argvt();
void	free_argvt(void *data);
void print_args(void *data);

static inline t_argv	*get_argv(t_llist *data)
{
	return ((t_argv *)(data->data));
}

#endif