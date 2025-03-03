/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:39:44 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/03 21:04:25 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/varhandler.h"
#include "../HashTable/hdrs/hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

int	main()
{
	char		*argt;
	char		*line;
	char		*data;
	t_hashtable	*hashtable;

	hashtable = crthashtable(32);
	while (1)
	{
		line = readline("Pablo Escobar:\t");
		if (!ft_strcmp(line, "exit"))
		{
			free(line);
			break ;
		}
		printf("ENTERED LINE:\t%s\n", line);
		varhandler(line, hashtable);
		argt = get_key_from_str(line);
		printf("KEY:\t%s\n", argt);
		data = (char *)hashtable->get_data(hashtable, argt);
		printf("VAR VALUE:\t%s\n", data);
		free(data);
		free(argt);
		free(line);
	}
	freehashtablet(hashtable);
}