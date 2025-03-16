/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:47:26 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/16 21:42:19 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata_service.h"
#include "../../splitter/hdrs/splitter.h"
#include "../../libft/libft.h"

t_cchar	*cmp_str_ret_crd(t_cchar *str, t_cchar **strv)
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

	operation = NULL;
	while (crd->i < crd->size)
	{
		operation = cmp_str_ret_crd(args + crd->i, operations);
		if (operation)
			break ;
		++crd->i;
	}
	if (!operation)
		return (E_OPER_SIZE);
	crd->i += ft_strlen(operation);
	return (_get_operation(operation, operations));
}

t_uchar	get_current_operation_code(t_cchar *args, t_cchar **operations)
{
	t_cchar	*operation;

	operation = cmp_str_ret_crd(args, operations);
	if (!operation)
		return (E_OPER_SIZE);
	return (_get_operation(operation, operations));
}
