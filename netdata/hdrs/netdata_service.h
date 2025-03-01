/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata_service.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:38:46 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/01 18:43:32 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETDATA_SERVICE_H
# define NETDATA_SERVICE_H

#include "../../libft/libft.h"
#include "netdata.h"

void		set_operation(t_cchar *data, t_uchar operation, t_argv *argvt);
t_uchar	get_operation(t_cchar *args, t_crd *crd, t_cchar **operations);

#endif