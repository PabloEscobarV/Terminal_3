/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter_srvs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:33:27 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/09 15:35:03 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITTER_SRVS_H
# define SPLITTER_SRVS_H

# include "../../libft/libft.h"

# define SPLIT_IN_DATA_CH	' '

void	skip_qts(t_cchar *str, t_crd *crd, t_splitter *splitters);
int		esc_ch_filter(t_cchar *str, t_crd *crd, t_cchar esc);
char	**transfer_str(const char *str);

#endif