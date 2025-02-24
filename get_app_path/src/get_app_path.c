/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_app_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:15:15 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/24 21:59:35 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/get_app_path.h"
#include "../../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

static char	**_get_paths(const char *app, const char **envp)
{
	char	*path;
	char	**paths;

	path = ft_get_env(PATH, envp);
	if (path)
	{
		paths = ft_split(path, PATH_SPLIT_CH);
	}
	free(path);
	return (paths);
}

static	void	_add_app_name_to_paths(const char *app, char **paths)
{
	char	*app_name;

	app_name = ft_strjoin(PATH_SLASH, (char *)app);
	if (paths && *paths)
	{
		while (*paths)
		{
			*paths = ft_strjoinfree(*paths, app_name, 0);
			++paths;
		}
	}
	free(app_name);
}

static char	*_get_app_path(char **paths)
{
	while (*paths)
	{
		if (!access(*paths, F_OK || X_OK))
			break ;
		++paths;
	}
	return (ft_strdup(*paths));
}

char	*get_app_path(const char *app, const char *path)
{
	char	*app_path;
	char	**paths;

	if (app && *app && path && *path)
	{
		paths = ft_split(path, PATH_SPLIT_CH); 
		if (paths)
		{
			_add_app_name_to_paths(app, paths);
			app_path = _get_app_path(paths);
		}
		ft_free_d((void **)paths);
	}
	return (app_path);
}

char	*get_app_path_envp(const char *app, const char **envp)
{
	char	*app_path;
	char	**paths;

	app_path = NULL;
	if (app && *app && envp)
	{
		paths = _get_paths(app, envp);
		if (paths)
		{
			_add_app_name_to_paths(app, paths);
			app_path = _get_app_path(paths);
		}
		ft_free_d((void **)paths);
	}
	return (app_path);
}
