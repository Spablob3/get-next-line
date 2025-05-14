/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedro <joapedro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:51:38 by joapedro          #+#    #+#             */
/*   Updated: 2025/05/14 15:07:57 by joapedro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 3
# endif 

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);
void ft_bzero(void *s, size_t n);
void *ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif

