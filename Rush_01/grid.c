/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaldias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:54:28 by tsaldias          #+#    #+#             */
/*   Updated: 2023/09/04 14:39:54 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_arg_valid(char *arg)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (arg[i])
	{
		if (i % 2 == 1 && arg[i] != ' ')
			return (0);
		if (arg[i] >= '0' && arg[i] <= '9')
			r++;
		else if (arg[i] != ' ')
			return (0);
		i++;
	}
	if (r % 4 > 0)
		return (0);
	return (r);
}

void	ft_get_sides(char *str, int *sides)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			sides[j] = str[i] - '0';
			j++;
		}
		i++;
	}
}

void	ft_put_sides_in_grid(int **grid, int *sides, int *format)
{
	int	x;

	x = 0;
	while (x < *format - 2)
	{
		grid[0][x + 1] = sides[x];
		grid[*format - 1][x + 1] = sides[*format - 2 + x];
		grid[x + 1][0] = sides[(*format - 2) * 2 + x];
		grid[x + 1][*format - 1] = sides[(*format - 2) * 3 + x];
		x++;
	}
}

int	**ft_get_grid(char *arg, int *format)
{
	int	**grid;
	int	*sides;
	int	i;

	*format = ft_arg_valid(arg); // je verifie si le nombre de chiffre en parametre est OK.
	if (*format > 0) // Creer la grille si format correct (! non divisible par 4)
	{
		*format /= 4; // Taille du cote de la grille 
		sides = (int *) malloc(sizeof(int) * (*format) * 4); // tableau de 16 chiffres pour ensemble des nombres passes
		ft_get_sides(arg, sides); // remplir sides avec les nombre passes 
		*format += 2; // on etend notre grille pour compter le cadre.
		grid = (int **) malloc(sizeof(int *) * (*format)); // allouer la premiere ligne de la grille
		i = 0;
		while (i < *format)
		{
			grid[i] = (int *) malloc(sizeof(int) * (*format)); // 'deplier' les colonnes
			i++;
		}
		ft_put_sides_in_grid(grid, sides, format); // on met ce qui est passe en parametre aux bons endroit de la grille ('le cadre')
		free(sides); //regler leak de memoire
		return (grid);
	}
	return (0); // s'il est impossible de creer la grille 
}
