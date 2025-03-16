/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata_service.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:38:46 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/16 21:34:19 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETDATA_SERVICE_H
# define NETDATA_SERVICE_H

#include "../../libft/libft.h"
#include "netdata.h"

#define NDS_SPLITERS	">>|>|<| "
#define NDS_SPLT			'|'


void		set_operation(t_cchar *data, t_uchar operation, t_argv *argvt);
t_uchar	get_operation_code(t_cchar *args, t_crd *crd, t_cchar **operations);
t_uchar	get_current_operation_code(t_cchar *args, t_cchar **operations);
t_cchar	*cmp_str_ret_crd(t_cchar *str, t_cchar **strv);

#endif