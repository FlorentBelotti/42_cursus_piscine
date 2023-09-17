/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:23:53 by fbelotti          #+#    #+#             */
/*   Updated: 2023/09/14 14:24:44 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_double(char *str, char c, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1); 
}

void	ft_union(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (check_double(s1, s1[i], i) == 1)
			write (1, &s1[i], 1);
		i++;
	}
	while (s2[j])
	{
		if (check_double(s2, s2[j], j) == 1 && check_double(s1, s2[j], i) == 1)
			write (1, &s2[j], 1);
		j++;
	}
	write (1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	ft_union(argv[1], argv[2]);
		return (0);
}
	

