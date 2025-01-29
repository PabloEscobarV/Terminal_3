/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:07:45 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/01/29 22:26:37 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/get_app_path.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>


static int read_data_from_stdi(char **str)
{
	printf("Enter applicaton name\n");
	*str = readline("Pablo Escobar:\t");
	if (!ft_strcmp(*str, "exit"))
			return (1);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	char	*app_path;
	char	*app_name;

	argv += argc;
	while (1)
	{
		if (read_data_from_stdi(&app_name))
			break;
		app_path = get_app_path(app_name, (const char **)envp);
		printf("Application PATH:\t%s\n", app_path);
		free(app_path);
	}
	return 0;
}
