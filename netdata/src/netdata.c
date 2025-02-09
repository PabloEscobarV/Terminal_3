/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:32:36 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/09 19:53:38 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../splitter/hdrs/splitter.h"
#include "../../libft/libft.h"

static const char	*_cmp_str_ch(const char ch, const char *strv)
{
	while (*strv && ch != *strv)
		++strv;
	return (strv);
}

static void	_skip_qts(t_cchar *data, t_crd *crd, t_cchar qts)
{
	while (crd->i < crd->size && data[crd->i] != qts)
		++crd->i;
}

static void	_find_end_fname(t_cchar *data, t_crd *crd, t_cchar *rsrvd)
{
	while (crd->i < crd->size && !(*_cmp_str_ch(data[crd->i], rsrvd)) && !ft_isspace(data[crd->i]))
		++crd->i;
}

static char	*_crdt_file_name(t_cchar *data, int i, t_crd *crd, char qts)
{
	char	*file_name;

	if (qts)
		++i;
	file_name = malloc((crd->i - i + 1) * sizeof(char));
	ft_strncpy(file_name, data + i, crd->i - i);
	return (file_name);
}

char	*_get_file_name(t_cchar *data, t_crd *crd, t_rsrvd *rsrvd)
{
	int	i;
	char	*qts;

	i = crd->i;
	qts = _cmp_str_ch(data + crd->i, rsrvd->qts);
	if (*qts)
	{
		++crd->i;
		_skip_qts(data, crd->i, *qts);
	}
	else
		_find_end_fname(data, crd, rsrvd->reserved);
	return (_crdt_file_name(data, i, crd, *qts));
}

t_uchar	_set_argvt_data(const char *data, t_argv *argvt)
{
	while (*data)
	{
		
	}
}

t_argv	*_set_argvt()
{

}

t_argv	*netdata(const char *args, const char **data, t_splt *splt)
{
	
}
