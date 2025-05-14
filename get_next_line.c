/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:31:43 by joapedro          #+#    #+#             */
/*   Updated: 2025/05/14 15:17:26 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_file(int fd)
{
	int		bytes_read;
	static char	read_buffer[BUFFER_SIZE + 1];
	char	*line;

	line = NULL;
	bytes_read = 1;
	while (!ft_strchr(read_buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			return (NULL);
		}
		if (bytes_read == 0)
		{
			break;
		}
		read_buffer[bytes_read] = '\0';
		line = ft_strjoin(line, read_buffer);
	}
	return (line);
}

char *get_next_line(int fd)
{
	char	*stash;


	stash = read_file(fd);
	return (stash);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);

	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	return (0);
}
