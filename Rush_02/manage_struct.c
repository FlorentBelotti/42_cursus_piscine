/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:26:31 by gaesteve          #+#    #+#             */
/*   Updated: 2023/09/10 20:26:57 by gaesteve         ###   ########.fr       */
/*   Updated: 2023/09/10 19:44:13 by gaesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "lib.h"

char	**manage_split(char **tab)
{
	char	*str_dict;
	ssize_t	len;

	len = dict_len();
	str_dict = dict_to_string(len, fd, *str_dict);
	tab = ft_split(str_dict, ": ");
	print_tab(tab);
	return (tab);
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i++]);
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

t_tab	**manage_strct(t_tab **strct, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = -1;
	k = -1;
	tab = ft_strtrim(tab, "\n");
	while (tab[i])
	{
		while (tab[i][++j])
		{
			strct[++k]->str_nbr = strdup(tab[j]);
			strct[k]->str_let = strdup(tab[j + 1]);
		}
		j = -1;
		i++;
	}
}

t_tab	**init_strct(void)
{
	t_tab	**strct;
	int		i;

	i = 0;
	strct = (t_tab **)malloc(sizeof(t_tab *) * 41 + 1);
	while (i < 41 + 1)
	{
		strct[i] = (t_tab *)malloc(sizeof(t_tab));
		i++;
	}
	strct[i] = 0;
	return (strct);
}
