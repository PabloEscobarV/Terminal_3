/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:02:34 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/24 21:27:41 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITTER_H
# define SPLITTER_H

#include "../../libft/libft.h"

char	**splitter(t_cchar *str, t_cchar *splt, t_cchar *skip_pair, t_cchar esc);

#endif