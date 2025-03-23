/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_oper_code.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:47:08 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/23 20:07:10 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../hdrs/splitter.h"

int	get_oper_crd_qts(t_cchar *str, t_crd *crd, t_cchar **operations)
{
	char	*tmp;

	tmp = ft_strchr(SPLT_QUETS, str[crd->i]);
	if (!tmp)
		return (E_FALSE);
	++crd->i;
	while (crd->i < crd->size)
	{
		if (str[crd->i] == *tmp && ft_escape(str, crd->i))
			break ;
		++crd->i;
	}
	return (E_TRUE);
}

int	get_oper_crd(t_cchar *str, t_crd *crd, t_cchar **operations)
{
	int	oper_code;
	int	escape;

	oper_code = E_ERR;
	while (crd->i < crd->size)
	{
		escape = ft_escape(str, crd->i);
		if (ft_strchr(SPLT_QUETS, str[crd->i]) && escape)
			break ;
		if (ft_isspace(str[crd->i]))
			break ;
		oper_code = ft_cmp_strv_crd(str + crd->i, operations);
		if (oper_code >= 0)
		{
			if (escape)
				break ;
			crd->i += ft_strlen(operations[oper_code]);
		}
		++crd->i;
	}
	return (oper_code);
}
