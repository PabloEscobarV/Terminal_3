/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: black <black@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:44:16 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/01/07 21:53:29 by black            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>

t_uint	get_insrt_size(t_cchar *str, t_uint data_size, t_cchar insrt_ch)
{
	t_uint	str_size;

	str_size = 0;
	if (data_size)
	{
		while (*str)
		{
			if (*str == insrt_ch)
				str_size += data_size;
			++str;
		}
	}
	return (str_size);
}

void	_str_insert(char *result, t_cchar *str, t_cchar *data, t_cchar insrt_ch)
{
	while (*str)
	{
		if (*str == insrt_ch)
			result = ft_strcpy(result, data);
		else
		{
			*result = *str;
			++result;
		}
		++str;
	}
}

char	*str_insert(const char *str, const char *data, const char insrt_ch)
{
	t_uint	result_size;
	t_uint	data_size;
	char		*result;

	if (!str || !data || !(*data))
		return (NULL);
	data_size = ft_strlen(data);
	result_size = get_insrt_size(str, data_size, insrt_ch);
	if (!result_size)
		return (NULL);
	result_size += ft_strlen(str) - result_size / data_size;
	result = malloc((result_size + 1) * sizeof(char));
	if (!result)
	{
		ft_perror("ERROR!!! (malloc)");
		exit(-1);
	}
	result[result_size] = '\0';
	_str_insert(result, str, data, insrt_ch);
	return (result);
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
		result = str_insert(str, str_to, insert);
		printf("reult:\t%s\n", result);
		free(str);
		free(str_to);
		free(result);
	}
	free(str);
	return (0);
}

// char	*ft_str_insert(const char *str, const char *str_to, int front, int rear)
// {
// 	char	*tmp;
// 	char	*result;

// 	if (!str_to || front > rear)
// 		return (NULL);
// 	result = malloc((front + ft_strlen(str + rear) + ft_strlen(str_to) + 1)
// 			* sizeof(char));
// 	tmp = ft_strncpy(result, str, front);
// 	tmp = ft_strcpy(tmp, str_to);
// 	ft_strcpy(tmp, str + rear);
// 	return (result);
// }

// char	*ft_str_insert_ch_ind(const char *str, const char *str_to, char insrt)
// {
// 	int	front;
// 	int	rear;

// 	if (!str_to || !insrt)
// 		return (NULL);
// 	front = 0;
// 	rear = 0;
// 	if (str)
// 	{
// 		while (str[front] && str[front] != insrt)
// 			++front;
// 		rear = front;
// 		while (str[rear] && !ft_isspace(str[rear]))
// 			++rear;
// 		if (!str[front])
// 			return (NULL);
// 	}
// 	return (ft_str_insert(str, str_to, front, rear));
// }

// char	*str_insert(const char *str, const char *str_to, int front, int rear)
// {
// 	char	*tmp;
// 	char	*result;

// 	if (!str_to || front > rear)
// 		return (NULL);
// 	result = malloc((front + ft_strlen(str + rear) + ft_strlen(str_to) + 1)
// 		* sizeof(char));
// 	tmp = ft_strncpy(result, str, front);
// 	tmp = ft_strcpy(tmp, str_to);
// 	ft_strcpy(tmp, str + rear);
// 	return (result);
// }

// char	*str_insert_ch_ind(const char *str, const char *str_to, char insrt)
// {
// 	int	front;
// 	int	rear;

// 	if (!str_to || !insrt)
// 		return (str);
// 	front = 0;
// 	rear = 0;
// 	if (str)
// 	{
// 		while (str[front] && str[front] != insrt)
// 			++front;
// 		rear = front;
// 		while (str[rear] && !ft_isspace(str[rear]))
// 			++rear;
// 		if (!str[front])
// 			return (str);
// 	}
// 	return (str_insert(str, str_to, front, rear));
// }

// int	main()
// {
// 	char	*str = NULL;
// 	char	*str_to = NULL;
// 	char	*result = NULL;
// 	char	insert;

// 	while (1)
// 	{
// 		if (read_data_from_stdi(&str, &str_to, &insert))
// 			break ;
// 		result = ft_str_insert_ch_ind(str, str_to, insert);
// 		printf("reult:\t%s\n", result);
// 		free(str);
// 		free(str_to);
// 		free(result);
// 	}
// 	free(str);
// 	return (0);
// }