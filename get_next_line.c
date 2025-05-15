/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:31:43 by joapedro          #+#    #+#             */
/*   Updated: 2025/05/15 15:23:04 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int			bytes_read;
	static char	read_buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	bytes_read = 1;
	line = ft_strjoin(line, read_buffer);
	while (!ft_strchr(read_buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		//if (bytes_read < BUFFER_SIZE)
		read_buffer[bytes_read] = '\0';
		line = ft_strjoin(line, read_buffer);
		shift(read_buffer);
	}
	return (line);
}
int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	
	/* line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	 */
	close(fd);
	return (0);
}
