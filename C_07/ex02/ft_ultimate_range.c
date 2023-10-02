/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:16:27 by fbelotti          #+#    #+#             */
/*   Updated: 2023/09/12 15:14:13 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	len;

	i = 0;
	len = max - min;
	if (min >= max)
		return (0);
	*range = (int *)malloc(sizeof(int) * len);
	if (*range == 0)
		return (0);
	while (i < len)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (i);
}
