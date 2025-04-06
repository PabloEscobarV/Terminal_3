/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:30:21 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/04/06 14:56:30 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../HashTable/hdrs/hashtable.h"
#include "../hdrs/varhandler.h"
#include "../../libft/libft.h"

static int	check_key(const char *var)
{
	if (ft_isdigit(*var))
		return (E_TRUE);
	while (ft_isalnum(*var) && *var != VH_EQL_SIGNE)
		++var;
	if (*var != VH_EQL_SIGNE)
		return (E_TRUE);
	return (E_FALSE);
}

char	*get_key_from_str(const char *str)
{
	const char	*key_end;

	key_end = str;
	while (*key_end && *key_end != VH_EQL_SIGNE)
		++key_end;
	if (check_key(str))
		return (NULL);
	return (ft_strldup(str, key_end - str));
}

int	varhandler(const char *str, t_hashtable *hst)
{
	char	*key;

	if (!str)
		return (E_ERR);
	key = get_key_from_str(str);
	if (!key)
		return (E_FALSE);
	str += ft_strlen(key) + 1;
	hst->add(hst, key, str);
	free(key);
	return (E_TRUE);
}
