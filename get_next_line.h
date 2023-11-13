/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:06:03 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/07 17:33:46 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h> // delete

char		*get_next_line(int fd);

char		*get_next_line_loop(int fd);

size_t	ft_strlen(const char *s);

char		*ft_dupcat(char *src1, char *src2, size_t start, size_t end);

size_t	ft_search_end(char *s, size_t start);

size_t	ft_get_end(char *s, size_t start);

char		*ft_meminit(size_t n);

void		ft_memclear(void *s, size_t n);

#endif