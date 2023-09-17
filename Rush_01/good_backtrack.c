/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_backtrack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <thomasdelan2@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:41:05 by truello           #+#    #+#             */
/*   Updated: 2023/09/04 15:17:40 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_verify_line(int **grid, int line, int format);
int	ft_verify_column(int **grid, int column, int format);
int	ft_is_grid_valid(int **grid, int format);
int	ft_is_valid(int **grid, int pos, int format, int grid_size);

int	test(int **grid, int pos, int gs, int val)
{
	while (val >= 1) // parce que min
	{
		grid[pos / gs][pos % gs] = val; // la ligne/colonne de travail (i) 
		if (pos / gs == gs - 2 && pos % gs == gs - 2) // si on est sur la derniere case de la grille de travail on verifie toute la grille.
		{
			if (ft_is_grid_valid(grid, gs - 2)) // validite de la grille
				return (1);
		}
		else if (pos % gs == gs - 2) // verification de toute la ligne a partir de la derniere colonne
		{
			if (ft_verify_line(grid, pos / gs, gs - 2)) // validite de la ligne 
				return (ft_is_valid(grid, pos + 1, gs - 2, gs));
		}
		else if (pos / gs == gs - 2) // verification de la colonne
		{
			if (ft_verify_column(grid, pos % gs, gs - 2)) // verification de la colonne
				return (ft_is_valid(grid, pos + 1, gs - 2, gs));
		}
		else if (ft_is_valid(grid, pos + 1, gs - 2, gs)) 
			// on passe a la case d'apres.  
			return (1);
		grid[pos / gs][pos % gs] = 0;
		val--;
	}
	return (0);
}

int	ft_is_valid(int **grid, int pos, int format, int grid_size)
{
	int	i;
	int	j;
	int	val; //valeur testee dans la case

	if (pos == grid_size * grid_size) //a la fin de la grille entiere on suppose que verif ok. 
		return (1);
	i = pos / grid_size; // ligne actuelle dans la grille entiere
	j = pos % grid_size; // colonne actuelle dans la grille entiere
	val = format; // parce qu'on commence par la valeur max
	if (i == 0 || i == grid_size - 1 || j == 0 || j == grid_size - 1) // dans le cas ou on sort de la grille de travail, on passe a la case suivante
	{
		return (ft_is_valid(grid, pos + 1, format, grid_size)); // on verifie la case suivante
	}
	if (grid[i][j] != 0) // Si  valeur n'est pas zero
	{
		if (ft_is_valid(grid, pos + 1, format, grid_size)) // si avec notre valeur il y a une soluce, on la garde. 
			return (1);
	}
	if (test(grid, pos, grid_size, format)) //
		return (1);
	return (0);
}
