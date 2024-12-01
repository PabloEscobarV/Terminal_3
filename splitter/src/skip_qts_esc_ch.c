/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_qts_esc_ch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:32:29 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/12/01 21:32:47 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../E_Codes/e_codes.h"

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

int	esc_ch_filter(t_cchar *str, t_crd *crd, t_cchar esc)
{
	int	tmp;

	if (!crd->i || str[crd->i - 1] != esc)
		return (E_TRUE);
	tmp = crd->i - 2;
	while (tmp > 0 && str[tmp] == esc)
		--tmp;
	return ((crd->i - tmp) % 2);
}
