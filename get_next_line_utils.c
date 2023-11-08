/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:05:49 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/07 17:06:06 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_dupcat_allocator(char *src1, char *src2, size_t end_line)
{
	char		*dst;
	size_t	i;
	size_t	j;
	size_t	size;

	size = ft_strlen(src1) + ft_strlen(src2);
	dst = (char *)malloc(sizeof(char) * (size  + 1));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (src1[j])
		dst[i++] = src1[j++];
	j = 0;
	while (src2[j] && j <= end_line)
		dst[i++] = src2[j++];
	dst[i] = 0;
	free(src1);
	return (dst);
}

int	ft_search_next_line(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
