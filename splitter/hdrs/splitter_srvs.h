/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter_srvs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:33:27 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/24 21:26:25 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITTER_SRVS_H
# define SPLITTER_SRVS_H

# include "../../libft/libft.h"

# define SPLIT_IN_DATA_CH	' '

typedef struct s_splt
{
	const char	**splitters;
	const char	**skip_pair;
}							t_splt;

void			skip_qts(t_cchar *str, t_crd *crd, t_cchar **qts, t_cchar esc);
int				esc_ch_filter(t_cchar *str, t_crd *crd, t_cchar esc);
char			**transfer_str(const char *str);

#endif