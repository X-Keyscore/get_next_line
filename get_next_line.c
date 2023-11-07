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

char    *get_next_line(int fd)
{
	fd = open("test", O_RDONLY);
	/*
    while (read(0, &c, 1) > 0)
	{
		if (c != '\n')
			nbr[i++] = c;
		else
		{
			nbr[i] = 0;
			ft_call_function("numbers.dict", dict, nbr, alloc_size);
			write(1, "\n", 1);
			i = 0;
		}
	}*/
}