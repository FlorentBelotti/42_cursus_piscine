/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:39:00 by truello           #+#    #+#             */
/*   Updated: 2023/09/04 15:24:37 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_skyscrapers_left(int **grid, int line, int format);
int	count_skyscrapers_right(int **grid, int line, int format);
int	count_skyscrapers_up(int **grid, int column, int format);
int	count_skyscrapers_down(int **grid, int column, int format);

// verifier les doublons

int	ft_is_line_valid(int **grid, int line, int format)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i <= format)
	{
		while (j <= format)
		{
			if (i != j && grid[line][i] == grid[line][j])
				return (0);
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

int	ft_is_col_valid(int **grid, int col, int format)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i <= format)
	{
		while (j <= format)
		{
			if (i != j && grid[i][col] == grid[j][col])
				return (0);
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}



int	ft_verify_line(int **grid, int line, int format)
{
	if (ft_is_line_valid(grid, line, format))
	{
		if (grid[line][0] > 0) // si parametre de gauche est valide  
			if (count_skyscrapers_left(grid, line, format) > grid[line][0])
				return (0); //trop de batiment car > au parametre
		if (grid[line][format + 1] > 0)
			if (count_skyscrapers_right(grid, line, format) \
				> grid[line][format + 1])
				return (0);
		return (1);
	}
	return (0); // en cas de doublons
}

int	ft_verify_column(int **grid, int column, int format)
{
	if (ft_is_col_valid(grid, column, format))
	{
		if (grid[0][column] > 0)
			if (count_skyscrapers_up(grid, column, format) > grid[0][column])
				return (0);
		if (grid[format + 1][column] > 0)
			if (count_skyscrapers_down(grid, column, format) \
				> grid[format + 1][column])
				return (0);
		return (1);
	}
	return (0);
}


// toutes les lignes et toutes les colonnes (la grille)
int	ft_is_grid_valid(int **grid, int format)
{
	int	i;

	i = 1;
	while (i <= format)
	{
		if (!ft_verify_line(grid, i, format) \
			|| !ft_verify_column(grid, i, format))
			return (0);
		i++;
	}
	return (1);
}
