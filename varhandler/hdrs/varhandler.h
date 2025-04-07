/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varhandler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:34:39 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/04/07 21:17:28 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARHANDLER_H
# define VARHANDLER_H

# include "../../HashTable/hdrs/hashtable.h"

# define VH_EQL_SIGNE	'='
# define VH_VARSIGNE	'$'

int		varhandler(const char *str, t_hashtable *hst);
char	*get_key_from_str(const char *str);

#endif