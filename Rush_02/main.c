/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:58:31 by yonieva           #+#    #+#             */
/*   Updated: 2023/09/10 21:21:45 by gaesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "lib.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (argv[1] < 0)
		{
			write(1, "Error", 5);
			return (1);
		}
		write(1, &str_dict, 1);
	}
	if (argc == 3)
	{
		if (argv[1] < 0)
		{
			write(1, "Error", 5);
			return (1);
		}
	}
	if (argc > 3)
	{
		write (1, "Veuillez saisir au maximum 2 arguments ex '54 18'", 49);
	}
}
