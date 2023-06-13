/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:34:29 by suminpar          #+#    #+#             */
/*   Updated: 2023/06/14 01:36:47 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *backup)
{
	int		read_size;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_size = 1;
	while (ft_strchr(backup, '\n') == 0 && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
	buffer[read_size] = '\0';
	backup = ft_strjoin(backup, buffer);
	}
	return (backup);
}

char	*ft_get_line(char *backup)
{
	int		i;
	char	*result;

	i = 0;
	if (backup[i] == '\0')
		return (0);
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	result = (char *)malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (backup[i] != '\0' && backup[i] != '\n')
	{
		result[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		result[i] = backup[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_free(char *backup)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (backup[i] != '\0' && backup[i] != '\n')
		i++;
	if (backup[i] == '\0')
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!result)
		return (NULL);
	i++;
	j = 0;
	while (backup[i] != '\0')
		result[j++] = backup[i++];
	result[j] = '\0';
	free(backup);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = ft_read_line(fd, backup);
	if (!backup)
		return (NULL);
	line = ft_get_line(backup);
	backup = ft_free(backup);
	return (line); 
}

#include <fcntl.h>
#include <stdio.h>

int main(void)
{
  int fd;

  fd = 0;
  fd = open("./test.txt", O_RDONLY);
  char *line = get_next_line(fd);
  printf("%p\n", line);
  printf("%s", line);

  return (0);
  
}