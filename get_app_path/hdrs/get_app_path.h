/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_app_path.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:36:53 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/24 21:50:18 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_APP_PATH_H
# define GET_APP_PATH_H

# define PATH 					"PATH"
# define PATH_SPLIT_CH	':'
# define PATH_SLASH			"/"

char	*get_app_path(const char *app, const char *path);
char	*get_app_path_envp(const char *app, const char **envp);

#endif	// GET_APP_PATH_H