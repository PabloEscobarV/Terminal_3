/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:27:48 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/01/30 20:49:21 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETDATA_H
#define NETDATA_H

# define ND_INFILE_RDR	"<"
# define ND_OUTFILE_RDR	">"
# define ND_APPEND_RDR	">>"
# define ND_HERDOC_RDR	"<<"

typedef enum	e_operations
{
	E_OPER_PIPE,
	E_OPER_OR,
	E_OPER_AND,
	E_OPER_SIZE
}							t_operations;

typedef struct	s_argv
{
	t_uchar				in_herdoc;
	t_uchar				out_append;
	char					*in_file;
	char					*out_file;
	char					**argv;
	t_operations	operation;
}								t_argv;

#endif