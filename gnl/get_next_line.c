/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:34:29 by suminpar          #+#    #+#             */
/*   Updated: 2023/06/27 17:27:38 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	fd_strchr(char *s)
{
	ssize_t	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (-1);
}

int	ft_free(char *result, char **backup, char **buffer, char **line)
{
	if (result == NULL)
	{
		if (backup != NULL && *backup != NULL)
		{
			free(*backup);
			*backup = NULL;
		}
		if (buffer != NULL && *buffer != NULL)
		{
			free(*buffer);
			*buffer = NULL;
		}
		if (line != NULL && *line != NULL)
		{
			free(*line);
			*line = NULL;
		}
		return (1);
	}
	else
		return (0);
}

char	*ft_read_line(int fd, char **buffer, char **backup)
{
	ssize_t		read_size;
	char		*tmp;

	read_size = 1;
	while (read_size)
	{
		read_size = read(fd, *buffer, BUFFER_SIZE);
		if (read_size == -1)
			return (NULL);
		(*buffer)[read_size] = '\0';
		if (read_size == 0)
			break ;
		if (*backup == NULL)
			tmp = ft_strdup(*buffer);
		else
			tmp = ft_strjoin(*backup, *buffer);
		(void)ft_free(NULL, backup, NULL, NULL);
		if (tmp == NULL)
			return (NULL);
		*backup = tmp;
		if (fd_strchr(*buffer) == 1)
			break ;
	}
	(void)ft_free(NULL, NULL, buffer, NULL);
	return (*backup);
}

char	*ft_backup_line(char **line)
{
	size_t		i;
	char		*result;

	i = 0;
	if (*line == NULL || (*line)[0] == '\0')
		return (NULL);
	while ((*line)[i] != '\n' && (*line)[i] != '\0')
		i++;
	result = ft_substr(*line, i + 1, ft_strlen(*line) - i);
	if (ft_free(result, NULL, NULL, line) == 1)
		return (NULL);
	if (result[0] == '\0')
	{
		ft_free(NULL, NULL, NULL, &result);
		return (NULL);
	}
	(*line)[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (ft_free(buffer, &backup, NULL, NULL) == 1)
		return (NULL);
	line = ft_read_line(fd, &buffer, &backup);
	if (ft_free(line, &backup, &buffer, NULL) == 1)
		return (NULL);
	backup = ft_backup_line(&line);
	if (line == NULL)
		return (NULL);
	buffer = ft_substr(line, 0, ft_strlen(line));
	ft_free(NULL, NULL, NULL, &line);
	if (ft_free(buffer, &backup, NULL, NULL) == 1)
		return (NULL);
	return (buffer);
}
