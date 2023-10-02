/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:32:53 by fbelotti          #+#    #+#             */
/*   Updated: 2023/09/13 09:33:47 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"	

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(str);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int argc, char **argv)
{
	int					i;
	struct s_stock_str	*tab;

	if (argc < 1)
		argc = 0;
	tab = malloc(sizeof(t_stock_str) * (argc + 1));
	i = 0;
	while (i < argc)
	{
		tab[i].size = ft_strlen(argv[i]);
		tab[i].str = argv[i];
		tab[i].copy = ft_strdup(argv[i]);
		i++;
	}
	return (tab);
}
