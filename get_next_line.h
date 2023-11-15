/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:06:03 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/15 12:29:23 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char		*get_next_line(int fd);

char		*ft_reader(int fd);

int			ft_write(char **line, char *buffer);

char		*ft_dupcat(char *src1, char *src2, size_t start, size_t end);

size_t		ft_strlen(const char *s);

char		*ft_meminit(size_t n);

void		ft_memclear(char *s, size_t n);

size_t		ft_search_end(char *s, size_t start);

size_t		ft_get_end(char *s, size_t start);

#endif