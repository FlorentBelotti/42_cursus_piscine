/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:44:12 by fbelotti          #+#    #+#             */
/*   Updated: 2023/09/10 20:38:48 by gaesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

int	dict_len(void)
{
	char			bf;
	ssize_t			len;
	ssize_t			temp;
	int				fd;

	len = 0;
	fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
	{
		write(1, "Dict Error\n", 11);
		close (fd);
		return (1);
	}
	temp = read(fb, &bf, 1);
	while (temp > 0)
		len++;
	if (temp < 0)
	{
		write(1, "Dict Error\n", 11);
		close (fd);
		return (1);
	}
	close (fd);
	return (len);
}

char	*dict_to_string(ssize_t len, int fd, char *str_dict)
{
	fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
	{
		write (1, "Dict Error\n", 11);
		close (fd);
		return (NULL);
	}
	str_dict = (char *)malloc(len + 1);
	if (str_dict == NULL)
	{
		write (1, "Memory Error\n", 13);
		close (fd);
		return (NULL);
	}
	if (read(fd, str_dict, len) != len)
	{
		write (1, "Dict Error\n", 11);
		free(str_dict);
		close(fd);
		return (NULL);
	}
	str_dict[len] = '\0';
	close (fd);
	return (str_dict);
}
