/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter_srvs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:33:27 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/23 20:07:57 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITTER_SRVS_H
# define SPLITTER_SRVS_H

# include "../../libft/libft.h"

int	get_oper_crd_qts(t_cchar *str, t_crd *crd, t_cchar **operations);
int	get_oper_crd(t_cchar *str, t_crd *crd, t_cchar **operations);

#endif