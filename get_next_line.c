/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:06:00 by anraymon          #+#    #+#             */
/*   Updated: 2024/01/01 23:27:50 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_get_start(char *s)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (s[i])
			return (i);
		i++;
	}
	return (i);
}

char	*ft_dupcat(char *src1, char *src2, size_t start, size_t end)
{
	char		*dst;
	size_t		i;
	size_t		j;
	size_t		size;

	size = ft_strlen(src1) + (end - start) + 1;
	if (!size)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (src1[j])
		dst[i++] = src1[j++];
	j = start;
	while (src2[j] && j <= end)
	{
		dst[i++] = src2[j];
		src2[j++] = 0;
	}
	dst[i] = 0;
	free(src1);
	return (dst);
}

int	ft_write(char **line, char *buffer)
{
	size_t	start;
	size_t	end;

	start = ft_get_start(buffer);
	if (ft_search_end(buffer, start))
	{
		end = ft_get_end(buffer, start);
		*line = ft_dupcat(*line, buffer, start, end);
		if (!*line)
			return (0);
		return (1);
	}
	*line = ft_dupcat(*line, buffer, start, BUFFER_SIZE);
	return (0);
}

char	*ft_reader(int fd, size_t read_count)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*line;

	line = ft_meminit(1);
	if (!line)
		return (NULL);
	while (1)
	{
		if (ft_get_start(buffer) < BUFFER_SIZE || read_count)
		{
			if (ft_write(&line, buffer) && line)
				return (line);
			if (!line)
				break ;
		}
		ft_memclear(buffer, BUFFER_SIZE);
		if (!read(fd, buffer, BUFFER_SIZE) && line && line[0])
			return (line);
		else if (!buffer[0])
			break ;
		read_count++;
	}
	if (line)
		free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	size_t	read_count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_count = 0;
	return (ft_reader(fd, read_count));
}
