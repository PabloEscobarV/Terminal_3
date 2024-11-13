/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:08:59 by black             #+#    #+#             */
/*   Updated: 2024/11/13 21:44:48 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/splitter.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>

static int read_data_from_stdi(char **str)
{
*str = readline("Pablo Escobar:\t");
if (!ft_strcmp(*str, "exit"))
    return (1);
return (0);
}

void print_matrix(const char **strv)
{
    if (!strv)
    {
        printf("NULL POINTER STRV\n");
        return;
    }
    while (*strv)
    {
        printf("|%s|\n", *strv);
        ++strv;
    }
}

int main()
{
    char *str = NULL;
    char **spltrs = NULL;
    char **result = NULL;
    char splt_ch = ' ';

    spltrs = ft_split("|| && | &", splt_ch);
    while (1)
    {
        if (read_data_from_stdi(&str))
            break;
        result = splitter((t_cchar *)str, (t_cchar **)spltrs);
        print_matrix((t_cchar **)result);
        free(str);
        ft_free_d((void **)result);
    }
    ft_free_d((void **)spltrs);
    free(str);
    return (0);
}
