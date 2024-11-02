/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:44:16 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/11/02 23:17:41 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>

char	*str_insert(const char *str, const char *str_to, int front, int rear)
{
	char	*tmp;
	char	*result;

	if (!str_to || front > rear)
		return (NULL);
	result = malloc((front + ft_strlen(str + rear) + ft_strlen(str_to) + 1)
		* sizeof(char));
	tmp = ft_strncpy(result, str, front);
	tmp = ft_strcpy(tmp, str_to);
	ft_strcpy(tmp, str + rear);
	return (result);
}

char	*str_insert_ch_ind(const char *str, const char *str_to, char insrt)
{
	int	front;
	int	rear;

	if (!str_to || !insrt)
		return (str);
	front = 0;
	rear = 0;
	if (str)
	{
		while (str[front] && str[front] != insrt)
			++front;
		rear = front;
		while (str[rear] && !ft_isspace(str[rear]))
			++rear;
		if (!str[front])
			return (str);
	}
	return (str_insert(str, str_to, front, rear));
}

static int	read_data_from_stdi(char **str, char **str_to, char *ch)
{
	char	*tmp;

	printf("Eneter string:\n");
	*str = readline("Pablo Escobar:\t");
	if (!ft_strcmp(*str, "exit"))
		return (1);
	printf("Eneter string to insert:\n");
	*str_to = readline("Pablo Escobar:\t");
	printf("Enetr insert character:\n");
	tmp = readline("Pablo Escobar:\t");
	*ch = *tmp;
	free(tmp);
	return (0);
}

int	main()
{
	char	*str = NULL;
	char	*str_to = NULL;
	char	*result = NULL;
	char	insert;

	while (1)
	{
		if (read_data_from_stdi(&str, &str_to, &insert))
			break ;
		result = ft_str_insert_ch_ind(str, str_to, insert);
		printf("reult:\t%s\n", result);
		free(str);
		free(str_to);
		free(result);
	}
	free(str);
	return (0);
}