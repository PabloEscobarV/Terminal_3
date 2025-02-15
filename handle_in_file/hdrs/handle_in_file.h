/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_in_file.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:29:28 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/15 20:42:55 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_IN_FILE_H
# define HANDLE_IN_FILE_H

# define DQOUTES	'"'
# define SQOUTES	'\''
# define ESC_CH		'\\'

void	move_symbol(char *args, const char *rsrvd_ch, const char symb);

#endif