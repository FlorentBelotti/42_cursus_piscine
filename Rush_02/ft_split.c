/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaesteve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:37:53 by gaesteve          #+#    #+#             */
/*   Updated: 2023/09/10 19:43:11 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

char	*ft_strdup(char *src, int start, int end)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (end - start + 1));
	if (dest == NULL)
		return (NULL);
	while (start + i < end)
	{
		if (src[start + i] != '\n')
		{
			dest[i++] = src[start + i];
			start++;
		}
		else
			i++;
	}
	dest[i] = 0;
	return (dest);
}

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (str[i])
	{
		while (is_sep(str[i], charset) && str[i])
		{
			i++;
		}
		if (str[i])
		{
			k++;
			while (!is_sep(str[i], charset) && str[i])
			{
				i++;
			}
		}
	}
	return (k);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		start;
	int		k;

	tab = malloc(sizeof(char *) * (count_word(str, charset) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		while (is_sep(str[i], charset) && str[i])
			i++;
		start = i;
		while (!is_sep(str[i], charset) && str[i])
			i++;
		if (i != start)
		{
			tab[k] = ft_strdup(str, start, i);
		}
		k++;
	}
	tab[k] = 0;
	return (tab);
}
