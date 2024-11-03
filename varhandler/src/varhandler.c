/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:30:21 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/30 22:07:43 by Pablo Escob      ###   ########.fr       */
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

static char	*variablevalue(const char *data)
{
	int		size;
	char	*var;

	size = 0;
	while (data[size] && !ft_isspace(data[size]))
		++size;
	var = malloc((size + 1) * sizeof(char));
	if (!var)
	{
		ft_putstr(STR_MALLOC_ERROR);
		exit(-1);
	}
	ft_strncpy(var, data, size);
	return (var);
}

const char	*varhandler(const char *str, t_hashtable *hst)
{
	const char	*tmp;
	char		*var;

	if (!str)
		return (str);
	tmp = str;
	while (*tmp && *tmp != VARSIGNE)
		++tmp;
	if (check_key(str))
		return (str);
	var = ft_strldup(str, tmp - str);
	str = tmp + 1;
	tmp = variablevalue(tmp + 1);
	str += ft_strlen(tmp);
	if (!(*str))
		hst->add(hst, var, tmp);
	free(var);
	free((void *)tmp);
	return (str);
}

const char	*get_key_from_str(const char *str)
{
	const char	*key;

	key = str;
	while (*str && *str != VARSIGNE)
		++str;
	if (!(*str))
		return (NULL);
	return ((const char *)ft_strldup(key, str - key));
}
