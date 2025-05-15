/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:59:34 by joapedro          #+#    #+#             */
/*   Updated: 2025/05/15 15:38:50 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		len;
	int		i;

	len = ft_strlen(s);
	c = (unsigned char)c;
	i = 0;
	while (i <= len)
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (0);
}
char	*ft_strjoin(char *line, char *read_buffer)
{
	char	*str;
	int		i;
	int 	j;

	if (!read_buffer)
		return (NULL);
	str = malloc((ft_strlen(line) + ft_strlen(read_buffer) + 1) * sizeof(char));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (line && line[i])
	{
		str[i] = line[i];
		i++;
	}
	j = 0;
	while (read_buffer[j])
	{
		str[i + j] = read_buffer[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

void	shift(char *read_buffer)
{
	int	i;
	int	j;

	i = 0;
	while (read_buffer[i] && read_buffer[i] != '\n')
		i++;
	if (read_buffer[i] == '\n')
		i++;
	j = 0;
	while (read_buffer[i + j])
	{
		read_buffer[j] = read_buffer[i + j];
		j++;
	}
	read_buffer[j] = '\0';
}
