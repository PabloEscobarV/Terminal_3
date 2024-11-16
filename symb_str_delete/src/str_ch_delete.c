/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ch_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:13:22 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/11/16 16:04:40 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include <stdlib.h>

static int	str_len_non_symb(const char *str, const char symb)
{
	int	size;

	size = 0;
	while (1)
	{
		if (str[size] == symb)
			++str;
		if (!str[size])
			break ;
		++size;
	}
	return (size);
}

static char	*str_cpy_nosymb(t_cchar *src, t_cchar symb, unsigned int size)
{
	int	i;
	char	*str;

	str = malloc((size + 1) * sizeof(char));
	if (!str)
	{
		ft_perror("MALLOC ERROR!!!");
		exit(-1);
	}
	i = 0;
	while (i < size)
	{
		if (src[i] == symb)
			++src;
		if (!src[i])
			break ;
		str[i] = src[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

char	*str_ch_delete(const char *src, const char symb)
{
	int		size;

	if (!src)
		return (NULL);
	size = str_len_non_symb(src, symb);
	if (!size)
		return (NULL);
	return (str_cpy_nosymb(src, symb, size));
}
