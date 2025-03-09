/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:47:26 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/09 12:28:14 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata_service.h"
#include "../../splitter/hdrs/splitter.h"
#include "../../libft/libft.h"

static t_cchar	*_cmp_str_ret_crd(t_cchar *str, t_cchar **strv)
{
	while (*strv && !ft_strlcmp(str, *strv))
		++strv;
	return (*strv);
}

static t_uchar	_get_operation(t_cchar *operation, t_cchar **operations)
{
	t_uchar	code;

	code = 0;
	while (operation && ft_strcmp(operation, operations[code]))
		++code;
	return (code);
}

t_uchar	get_operation_code(t_cchar *args, t_crd *crd, t_cchar **operations)
{
	t_cchar	*operation;

	while (crd->i < crd->size)
	{
		operation = _cmp_str_ret_crd(args + crd->i, operations);
		if (operation)
			break ;
		++crd->i;
	}
	if (!operation)
		return (E_OPER_SIZE);
	crd->i += ft_strlen(operation);
	return (_get_operation(operation, operations));
}
