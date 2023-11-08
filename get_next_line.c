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

char	*get_next_line_loop(int fd)
{
	char	*dst;
	char	*buffer;
	int		on_read;
	int		end_line;

	dst = malloc(1 * sizeof(char));
	dst[0] = 0;
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	on_read = 1;
	while (on_read)
	{
		read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE-1] = 0;
		end_line = ft_search_next_line(buffer);
		if (end_line != -1)
			on_read = 0;
		dst = ft_dupcat_allocator(dst, buffer, end_line);
	}
	free(buffer);
	if (!on_read)
		return (dst);
	return (NULL);
}

char	*get_next_line(int fd)
{
	return (get_next_line_loop(fd));
	/*
	char	*res;
	static size_t	old_line = 0;
	size_t				i;

	i = 0;
	while (i < old_line)
	{
		res = get_next_line_loop(fd);
		if (res)
		{
			free(res);
			i++;
		}
		else
			return (NULL);
	}
	if (i == old_line)
		return (get_next_line_loop(fd));
	return (NULL);*/
}