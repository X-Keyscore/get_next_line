/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:06:00 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/07 17:47:45 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_meminit(size_t n)
{
	char		*buffer;
	size_t	i;

	buffer = malloc(n * sizeof(char));
	i = 0;
	while (i < n)
		buffer[i++] = 0;
	return (buffer);
}

void		ft_memclear(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(unsigned char *)(s + i++) = 0;
}

size_t		ft_write_line(char **line, char *buffer, size_t last_end, size_t read_count)
{
	size_t	start;
	size_t	end;

	if (read_count == 0)
		start = last_end;
	else
		start = 0;
	end = ft_search_end(buffer, start);
	if (end)
	{
		end = ft_get_end(buffer, start);
		*line = ft_dupcat(*line, buffer, start, end);
		//printf("1 line = %s\n", *line);
		return (end + 1);
	}
	else
	{
		*line = ft_dupcat(*line, buffer, start, BUFFER_SIZE - 1);
		return (-1);
	}
}

char	*get_next_line(int fd)
{
	static size_t	last_end;
	static char		buffer[BUFFER_SIZE];
	char		*line;
	size_t	read_count;
	size_t	res_write_line;

	line = ft_meminit(1);
	read_count = 0;
	while (1)
	{
		//printf("\nbuffer = %s\n", buffer);
		if (last_end || read_count)
		{
			res_write_line = ft_write_line(&line, buffer, last_end, read_count);
			//printf("\nres = %ld\n", res_write_line);
			if (res_write_line != -1)
			{
				last_end = res_write_line;
				if (!line[0])
					return (NULL);
				return (line);
			}
		}
		ft_memclear(buffer, BUFFER_SIZE);
		read(fd, buffer, BUFFER_SIZE-1);
		read_count++;
	}
	return (NULL);
}