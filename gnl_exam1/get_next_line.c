/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:28:56 by wouter            #+#    #+#             */
/*   Updated: 2024/07/16 17:24:36 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_and_return(char *return_val, char *str1, char **str2)
{
	if (str1 != NULL)
		free(str1);
	if (*str2 != NULL)
	{
		free(*str2);
		*str2 = NULL;
	}
	return (return_val);
}

char	*get_one_line(char **staticbuff)
{
	int		pos;
	char	*result;
	char	*temp;

	if (**staticbuff == '\0')
		return (free_and_return(NULL, NULL, staticbuff));
	pos = ft_strchr(*staticbuff, '\n');
	if (pos == -1)
	{
		result = ft_strjoin(*staticbuff, "");
		*staticbuff = NULL;
		return (result);
	}
	result = ft_substr(*staticbuff, 0, pos);
	temp = *staticbuff;
	*staticbuff = ft_substr(*staticbuff, pos + 1,
			ft_strlen(*staticbuff) - 1);
	free(temp);
	if (result == NULL || *staticbuff == NULL)
		return (free_and_return(NULL, result, staticbuff));
	return (result);
}

char	*read_from_file(int fd, char **staticbuff)
{
	char	*buff;
	int		bytes_read;

	buff = malloc(BUFFER_SIZE + 1);
	while (ft_strchr(*staticbuff, '\n') == -1)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_and_return(NULL, buff, staticbuff));
		if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		*staticbuff = ft_strjoin(*staticbuff, buff);
		if (staticbuff == NULL)
			return (free_and_return(NULL, buff, staticbuff));
	}
	free(buff);
	return (get_one_line(staticbuff));
}

char	*get_next_line(int fd)
{
	static char	*staticbuff;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (free_and_return(NULL, NULL, &staticbuff));
	if (staticbuff == NULL)
	{
		staticbuff = malloc(1);
		if (staticbuff == NULL)
			return (NULL);
		staticbuff[0] = '\0';
	}
	return (read_from_file(fd, &staticbuff));
}
