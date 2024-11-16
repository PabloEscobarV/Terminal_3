/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:00:25 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/11/16 16:09:23 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "hdrs/str_ch_delete.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

static int read_data_from_stdi(char **str)
{
	*str = readline("Pablo Escobar:\t");
	if (!ft_strcmp(*str, "exit"))
			return (1);
	return (0);
}

int main()
{
	char splt_ch = '\\';
	char *str = NULL;
	char *result = NULL;

	while (1)
	{
		if (read_data_from_stdi(&str))
				break;
		result = str_ch_delete(str, splt_ch);
		printf("entered string:\n|%s|\nResult string:\n|%s|\n", str, result);
		free(str);
		free(result);
	}
	free(str);
	return (0);
}
