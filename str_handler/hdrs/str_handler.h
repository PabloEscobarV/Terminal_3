/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:49:27 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/04/07 22:13:00 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_HANDLER_H
# define STR_HANDLER_H

#include "../../libft/libft.h"
#include "../../HashTable/hdrs/hashtable.h"

# define SH_DQTS	'\"'
# define SH_SQTS	'\''

t_llist	*str_handler(t_cchar *str, t_cchar **operations, t_hashtable *hst);

#endif