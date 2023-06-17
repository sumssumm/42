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

char	*ft_read_line(int fd, char *buffer, char *backup)
{
	int		read_size;
	char	*tmp;

	read_size = 1;
	while (read_size)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
			return (0);
		if (read_size == 0)
			break ;
		buffer[read_size] = '\0';
		if(!backup)
			backup = ft_strdup("");
		tmp = backup;
		backup = ft_strjoin(tmp, buffer);
		free(tmp);
		if(!backup)
			return (0);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backup);
}

char *ft_backup_line(char *line)
{
	int		i;
	char	*result;

	i = 0;
	if (line[i] == '\0')
		return (0);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	result = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!result)
		return (0);
	if (result[0] == '\0')
	{
		free(result);
		result = NULL;
		return (0);
	}
	line[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*backup; // 읽어온 파일을 저장하는 정적변수
	char		*buffer; // read()로 BUFFER_SIZE만큼 받아올 버퍼
	char		*line; // 결과값
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_read_line(fd, buffer, backup);
	free(buffer);
	if(line == NULL)
	{
		if (backup != NULL)
		{
			free(backup);
			backup = NULL;
		}
		return (NULL);
	}
	backup = ft_backup_line(line);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main(void)
// {
//   int fd;

//   fd = 0;
//   fd = open("./test.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
//   printf("%p\n", line);
//   printf("%s", line);
// 	line = get_next_line(fd);
//   printf("%p\n", line);
//   printf("%s", line);

//   return (0);
  
// }
