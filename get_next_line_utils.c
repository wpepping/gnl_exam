/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:46:08 by wouter            #+#    #+#             */
/*   Updated: 2024/07/16 17:07:12 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i++] != '\0')
		;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*result;
	char	*p;
	char	*temp;

	if (str1 == NULL)
		return (NULL);
	if (str2 == NULL)
		return (str1);
	result = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (result == NULL)
		return (NULL);
	p = result;
	temp = str1;
	while (*str1)
		*(p++) = *(str1++);
	while (*str2)
		*(p++) = *(str2++);
	*p = '\0';
	free(temp);
	return (result);
}

int	ft_strchr(char *str, char chr)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == chr)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char *str, int start, int end)
{
	char	*result;
	int		i;

	result = malloc(end - start + 2);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < end - start + 1)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
