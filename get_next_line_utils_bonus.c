/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:05:49 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/27 19:10:49 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_meminit(size_t n)
{
	char	*buffer;
	size_t	i;

	buffer = malloc(n * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < n)
		buffer[i++] = 0;
	return (buffer);
}

void	ft_memclear(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		s[i++] = 0;
}

size_t	ft_search_end(char *s, size_t start)
{
	size_t	i;

	i = start;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	if (i != BUFFER_SIZE)
		return (1);
	return (0);
}

size_t	ft_get_end(char *s, size_t start)
{
	size_t	i;

	i = start;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	if (i != BUFFER_SIZE)
		return (i);
	return (0);
}
