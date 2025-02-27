/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata_service.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:38:46 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/27 20:59:15 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETDATA_SERVICE_H
# define NETDATA_SERVICE_H

#include "../../libft/libft.h"
#include "netdata.h"

t_uchar	set_operation(t_cchar *data, t_uchar operation, t_argv *argvt);
void	set_arg_list(t_cchar *data, t_argv *argvt);
#endif