/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: black <black@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:07:46 by black             #+#    #+#             */
/*   Updated: 2024/11/14 14:16:52 by black            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	cmp_strv(const char *str, const char **spltrs)
{
	while (*spltrs && !ft_strlcmp(str, *spltrs))
		++spltrs;
	return (ft_strlen(*spltrs));
}
