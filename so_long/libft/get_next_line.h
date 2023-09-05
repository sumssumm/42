/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:34:09 by suminpar          #+#    #+#             */
/*   Updated: 2023/08/31 11:23:27 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char **buffer, char **backup);
char	*ft_backup_line(char **line);
int		ft_free(char *result, char **backup, char **buffer, char **line);
ssize_t	gnl_strchr(char *s);

char	*gnl_strdup(const char *s1);
void	*gnl_memcpy(void *dst, const void *src, size_t n);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_substr(char const *s, size_t start, size_t len);
size_t	gnl_strlen(const char *s);

#endif
