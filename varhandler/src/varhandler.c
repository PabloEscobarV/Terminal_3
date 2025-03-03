/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:30:21 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/03 21:04:15 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../HashTable/hdrs/hashtable.h"
#include "../../E_Codes//e_codes.h"
#include "../hdrs/varhandler.h"

static int	check_key(const char *var)
{
	if (ft_isdigit(*var))
		return (E_KO);
	while (ft_isalnum(*var) && *var != VARSIGNE)
		++var;
	if (*var != VARSIGNE)
		return (E_KO);
	return (E_OK);
}

char	*get_key_from_str(const char *str)
{
	const char	*key_end;

	key_end = str;
	while (*key_end && *key_end != VARSIGNE)
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
		return (E_KO);
	str += ft_strlen(key) + 1;
	hst->add(hst, key, str);
	free(key);
	return (E_OK);
}
