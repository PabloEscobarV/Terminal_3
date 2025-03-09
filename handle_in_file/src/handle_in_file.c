/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_in_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:39:25 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/09 15:01:18 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/handle_in_file.h"
#include "../../libft/libft.h"

static inline void	_move_one_back(char *args)
{
	*(args - 1) = *args;
}

static const char	*_cmp_str_ch(const char ch, const char *strv)
{
	while (*strv && ch != *strv)
		++strv;
	return (strv);
}

static void	_handle_in_file(char *args, t_cchar *rsrvd, t_cchar symb)
{
	_move_one_back(args);
	++args;
	while (*args
		&& *args != HIN_SPACE
		&& (*(args - 1) != ESC_CH
		&& !*_cmp_str_ch(*args, rsrvd)))
	{
		_move_one_back(args);
		++args;
	}
	--args;
	_move_one_back(args);
	*args = symb;
}

static void	_handle_in_file_qts(char *args, t_cchar qts, t_cchar symb)
{
	_move_one_back(args);
	++args;
	while (*args && !(*args == qts && *(args - 1) != ESC_CH))
	{
		_move_one_back(args);
		++args;
	}
	_move_one_back(args);
	*args = symb;
}

void	move_symbol(char *args, t_cchar *rsrvd_ch, t_cchar symb)
{
	char	tmp;

	if (!args || !rsrvd_ch)
		return ;
	args = (char *)ft_skip_spaces((const char *)args);
	if (*args == symb && *(args + 1))
	{
		*args = ' ';
		++args;
		args = (char *)ft_skip_spaces(args);
		tmp = *_cmp_str_ch(*args, rsrvd_ch);
		if (tmp == DQOUTES || tmp == SQOUTES)
			_handle_in_file_qts(args, tmp, symb);
		else
			_handle_in_file(args, rsrvd_ch, symb);
	}
}
