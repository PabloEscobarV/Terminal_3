/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: black <black@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:08:59 by black             #+#    #+#             */
/*   Updated: 2024/11/11 16:20:21 by black            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/splitter.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>

static int read_data_from_stdi(char **str)
{
    printf("Eneter string:\n");
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
        printf("%s\n", *strv);
        ++strv;
    }
}

int main()
{
    char *tmp = NULL;
    char *str = NULL;
    char *str_to = NULL;
    char **spltrs = NULL;
    char **result = NULL;
    char splt_ch;

    printf("Eneter string to split:\n");
    str_to = readline("Pablo Escobar:\t");
    printf("Enetr split character:\n");
    tmp = readline("Pablo Escobar:\t");
    splt_ch = *tmp;
    free(tmp);
    while (1)
    {
        if (read_data_from_stdi(&str))
            break;
        spltrs = ft_split(str_to, splt_ch);
        result = splitter((t_cchar *)str, (t_cchar **)spltrs);
        print_matrix((t_cchar **)result);
        free(str);
        free(str_to);
        ft_free_d((void **)result);
    }
    ft_free_d((void **)spltrs);
    ft_free_d((void **)result);
    return (0);
}
