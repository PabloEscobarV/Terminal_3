/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:28:20 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/15 20:51:39 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/handle_in_file.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

int	main()
{
	t_cchar	in_redir = '<';
	t_cchar	*rsrv_ch = "|$<>\"\'";
	char		*args;

	while (1)
	{
		args = readline("Pablo Escobar:\t");
		if (!ft_strcmp(args, "exit"))
			break ;
		move_symbol(args, rsrv_ch, in_redir);
		printf("RESULT:\t|%s|\n", args);
		free(args);
	}
	free(args);
	return (0);
}