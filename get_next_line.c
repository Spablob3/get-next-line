/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:31:43 by joapedro          #+#    #+#             */
/*   Updated: 2025/05/09 15:15:00 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int		read_char;
	char	*buffer;
	static char	*stash;
	char	*line;

	read_char = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	*buffer = 0;
	while (!ft_strchr(buffer, '\n') && read_char != 0 )
	{
		read_char = read(fd, buffer, BUFFER_SIZE);
		if (read_char == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (read_char == 0)
		{
			free(buffer);
			break;
		}
		buffer[read_char] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	line = ft_strndup(stash, '\n');
	stash = ft_substr(stash, ft_strlen(line), ft_strlen(stash) - ft_strlen(line));
	return (stash);
	
}
int	main(void)
{
	int fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);

	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
}
