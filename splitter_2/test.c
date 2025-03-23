/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:08:59 by black             #+#    #+#             */
/*   Updated: 2025/03/23 20:08:18 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/splitter.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>

static int read_data_from_stdi(char **str)
{
*str = readline("Pablo Escobar:\t");
if (!ft_strcmp(*str, "exit"))
    return (1);
return (0);
}

void print_args(void *data)
{
	t_args	*argst = (t_args *)data;

	printf("OPERATION CODE:\t%d\nDATA:\t|%s|\n-------------\n", argst->operation, argst->data);
}

int main()
{
	char		*str = NULL;
	t_llist	*result = NULL;
	char		**operations = ft_split(SPLT_OPERATIONS, SPLT_SPLIT_OPER);
	printf("SIZE OF t_args:\t%ld\n", sizeof(t_args));
	while (1)
	{
		if (read_data_from_stdi(&str))
				break;
		result = splitter((t_cchar *)str, (t_cchar **)operations);
		llistiter(result, print_args);
		free(str);
		llistclear(&result, free_t_args);
	}
	free(str);
	ft_free_d((void **)operations);
	return (0);
}
