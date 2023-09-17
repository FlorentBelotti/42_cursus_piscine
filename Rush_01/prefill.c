/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:45:40 by truello           #+#    #+#             */
/*   Updated: 2023/09/03 22:33:01 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_prefill_rows(int **grid, int format)
{
	int	i;
	int	j;

	i = 1;
	while (i < format - 2)
	{
		j = 0;
		if (grid[0][i] == 1)
			grid[1][i] = format - 2;
		if (grid[0][i] == format - 2)
			while (++j <= format - 2)
				grid[j][i] = j;
		if (grid[format - 1][i] == 1)
			grid[format - 2][i] = format - 2; 
		if (grid[format - 1][i] == format - 2)
			while (++j < format - 1)
				grid[format - 2 - j][i] = j;
		i++;
	}
}

void	ft_prefill_cols(int **grid, int format)
{
	int	i;
	int	j;

	i = 1;
	while (i < format - 2)
	{
		j = 0;
		if (grid[i][0] == 1)
			grid[i][1] = format - 2;
		if (grid[i][0] == format - 2)
			while (++j <= format - 2)
				grid[i][j] = j;
		if (grid[i][format - 1] == 1)
			grid[i][format - 2] = format - 2;
		if (grid[i][format - 1] == format - 2)
			while (++j <= format - 2)
				grid[i][format - 1 - j] = j;
		i++;
	}
}
