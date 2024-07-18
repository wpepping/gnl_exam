/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wouter <wouter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:37:20 by wouter            #+#    #+#             */
/*   Updated: 2024/07/17 22:58:16 by wouter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd);

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("multiple_line_no_nl", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	printf("-\n");
	free(line);
	line = get_next_line(-1);
	close(fd);
	fd = open("multiple_line_no_nl", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
