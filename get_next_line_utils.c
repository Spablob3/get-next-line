/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:59:34 by joapedro          #+#    #+#             */
/*   Updated: 2025/05/09 15:16:28 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	c = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (0);
}
char	*ft_strndup(const char *s, char c)
{
	char	*ptr;
	int		size;
	int		i;

	size = ft_strlen(s);
	ptr = malloc((size + 2) * sizeof(char));
	if (ptr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] && s[i] != c)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\n';
	ptr[i + 1] = '\0';
	return (ptr);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (start > ft_strlen(s))
	{
		return (ft_strndup("", '\0'));
	}
	if (len > ft_strlen(s + start))
	{
		len = ft_strlen(s + start);
	}
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}