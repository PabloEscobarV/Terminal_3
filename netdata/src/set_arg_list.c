/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arg_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:47:26 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/27 21:04:09 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../libft/libft.h"
#include "../../get_app_path/hdrs/get_app_path.h"
#include "../../splitter/hdrs/splitter.h"

void	set_arg_list(t_cchar *data, t_argv *argvt)
{
	char	*path;

	path = getenv(PATH);
	argvt->argv = splitter(data, " ", ND_SKIP_PAIR, ND_ESC_CH);
	argvt->app_path = get_app_path(argvt->argv[0], path);
	free(path);
}
