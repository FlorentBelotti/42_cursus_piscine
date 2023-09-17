/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:21:48 by fbelotti          #+#    #+#             */
/*   Updated: 2023/09/07 16:26:58 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0; 
	if (argc < 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	else
	{
		while (argv[argc - 1][i])
			write (1, &argv[argc - 1][i++], 1);
		write (1, "\n", 1);
	}
	return (0);
}

