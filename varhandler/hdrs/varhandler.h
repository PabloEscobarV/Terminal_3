/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varhandler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:34:39 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/30 22:07:38 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARHANDLER_H
# define VARHANDLER_H

# include "../../HashTable/hdrs/hashtable.h"

# define VARSIGNE	'='

const char	*varhandler(const char *str, t_hashtable *hst);
const char	*get_key_from_str(const char *str);

#endif