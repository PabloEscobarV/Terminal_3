/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_qts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:32:29 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/11/14 21:36:12 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	cmp_str_ret_crd(t_cchar *str, t_cchar **strv)
{
	int	i;

	i = 0;
	while (strv[i] && !ft_strlcmp(str, strv[i]))
		++i;
	return (i);
}

void	skip_qts(t_cchar *str, t_crd *crd, t_cchar *qt)
{
	crd->i += ft_strlen(qt);
	while (crd->i < crd->size && !ft_strlcmp(str + crd->i, qt))
		++crd->i;
}
