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

char		*ft_dupcat_allocator(char *src1, char *src2, size_t end_line);

int			ft_search_next_line(char *s);

#endif