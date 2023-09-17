/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_skyscrapers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:31:00 by fbelotti          #+#    #+#             */
/*   Updated: 2023/09/03 23:21:30 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_skyscrapers_left(int **grid, int line, int format)
{
	int	height;
	int	count;
	int	i;

	height = 0;
	count = 0;
	i = 1;
	while (i <= format)
	{
		if (grid[line][i] > height)
		{
			count++;
			height = grid[line][i];
		}
		i++;
	}
	return (count);
}

int	count_skyscrapers_right(int **grid, int line, int format)
{
	int	height;
	int	count;
	int	i;

	height = 0;
	count = 0;
	i = 0;
	while (i < format)
	{
		if (grid[line][format - i] > height)
		{
			count++;
			height = grid[line][format - i];
		}
		i++;
	}
	return (count);
}

int	count_skyscrapers_up(int **grid, int column, int format)
{
	int	height;
	int	count;
	int	i;

	height = 0;
	count = 0;
	i = 1;
	while (i <= format)
	{
		if (grid[i][column] > height)
		{
			count++;
			height = grid[i][column];
		}
		i++;
	}
	return (count);
}

int	count_skyscrapers_down(int **grid, int column, int format)
{
	int	height;
	int	count;
	int	i;

	height = 0;
	count = 0;
	i = 0;
	while (i < format)
	{
		if (grid[format - i][column] > height)
		{
			count++;
			height = grid[format - i][column];
		}
		i++;
	}
	return (count);
}
