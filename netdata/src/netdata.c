/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:32:36 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/16 19:56:40 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../splitter/hdrs/splitter.h"
#include "../../libft/libft.h"

static t_cchar	*_cmp_str_ret_crd(t_cchar *str, t_cchar **strv)
{
	while (*strv && !ft_strlcmp(str, *strv))
		++strv;
	return (strv);
}

static t_uchar	*_get_oper(t_cchar *args, t_crd *crd, t_cchar **data,
				t_cchar **splt)
{
	t_cchar	*operation;

	crd->i += ft_strlen(data);
	while (crd->i < crd->size)
	{
		operation = cmp_str_ret_crd(args + crd->i, splt);
		if (operation)
			break ;
		++crd->i;
	}
	crd->i += ft_strlen(operation);
	return (operation);
}

t_cchar	_get_oper_code(t_cchar *operation)
{
	
}

t_argv	*netdata(const char *args, const char **data, t_splt *splt)
{
	
}
