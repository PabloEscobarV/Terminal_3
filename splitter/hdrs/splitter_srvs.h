/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter_srvs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:33:27 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/11/14 21:39:06 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITTER_SRVS_H
# define SPLITTER_SRVS_H

# include "../../libft/libft.h"

void	skip_qts(t_cchar *str, t_crd *crd, t_cchar *qt);
int		cmp_str_ret_crd(t_cchar *str, t_cchar **strv);

#endif