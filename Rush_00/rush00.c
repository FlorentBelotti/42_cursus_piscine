/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:18:04 by fbelotti          #+#    #+#             */
/*   Updated: 2023/08/27 15:53:19 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_score(int x)
{
	int	i;

	i = 0;
	ft_putchar('o');
	if (x > 1)
	{
		while (i < x - 2)
		{
			ft_putchar('-');
			i++;
		}
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	ft_pipe(int x)
{
	int	i;

	i = 0;
	ft_putchar('|');
	if (x > 1)
	{
		while (i < x - 2)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('|');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (x < 1 || y < 1)
	{
		return ;
	}
	i = 0;
	ft_score(x);
	if (y > 1)
	{
		while (i < y - 2)
		{
			ft_pipe(x);
			i++;
		}
		ft_score(x);
	}
}
