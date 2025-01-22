/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_app_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:15:15 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/01/22 22:52:28 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/get_app_path.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char **argv, char **envp)
{
	print_matrix((const char **)envp);
	char *path = ft_get_env(PATH, (const char **)envp);

	printf("%s\n", path);
	free(path);
	return 0;
}
