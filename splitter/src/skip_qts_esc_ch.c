/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_qts_esc_ch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:32:29 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/09 15:21:45 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"
#include "../hdrs/splitter_srvs.h"
#include "../../libft/libft.h"
#include "../../E_Codes/e_codes.h"

void	skip_qts(t_cchar *str, t_crd *crd, t_splitter *splitters)
{
	t_cchar	*qt;

	qt = ft_cmp_strv(str + crd->i, splitters->skip_pair);

	if (qt && esc_ch_filter(str, crd, splitters->ecs_split))
	{
		crd->i += ft_strlen(qt);
		while (crd->i < crd->size)
		{
			if (ft_strlcmp(str + crd->i, qt) && esc_ch_filter(str, crd, splitters->ecs_split))
				break ;
			++crd->i;
		}
	}
}

int	esc_ch_filter(t_cchar *str, t_crd *crd, t_cchar esc)
{
	int	tmp;

	tmp = crd->i - 1;
	while (tmp >= 0 && str[tmp] == esc)
		--tmp;
	if (tmp < 0)
		tmp = 1;
	return ((crd->i - tmp) % 2);
}

char	**transfer_str(const char *str)
{
	char	**argv;

	argv = malloc(2 * sizeof(char *));
	if (!argv)
	{
		ft_perror("ALLOCATION ERROR!!!");
		exit(-1);
	}
	*argv = ft_strdup(str);
	argv[1] = NULL;
	return (argv);
}
