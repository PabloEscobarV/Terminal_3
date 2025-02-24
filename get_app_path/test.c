/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:07:45 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/24 21:59:30 by Pablo Escob      ###   ########.fr       */
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
	char	*path;
	char	*app_path;
	char	*app_name;

	argv += argc;
	path = getenv(PATH);
	printf("PATH:\t%s\n", path);
	while (1)
	{
		if (read_data_from_stdi(&app_name))
			break;
		app_path = get_app_path_envp(app_name, (const char **)envp);
		printf("Application PATH (get_app_path_env):\t%s\n", app_path);
		free(app_path);
		app_path = get_app_path(app_name, path);
		printf("Application PATH (get_app_path):\t%s\n", app_path);
		free(app_path);
	}
	free(path);
	return 0;
}
