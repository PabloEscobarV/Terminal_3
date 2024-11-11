/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: black <black@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:02:34 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/11/11 16:09:13 by black            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITTER_H
# define SPLITER_H

typedef struct s_crd
{
	int	i;
	int	size;
}		t_crd;

char	**splitter(const char *str, const char **spltrs);

#endif