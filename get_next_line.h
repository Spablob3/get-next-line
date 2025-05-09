/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:51:38 by joapedro          #+#    #+#             */
/*   Updated: 2025/05/09 15:16:50 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 5
# endif 

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif

