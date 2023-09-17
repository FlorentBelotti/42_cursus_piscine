/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:41:43 by fbelotti          #+#    #+#             */
/*   Updated: 2023/09/07 17:18:29 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	alpha_pos;
	int	alpha_count;

	i = 0;
	if (argc != 2)
	{
		ft_putchar('\n');
	}
	while (argv[1][i])
	{
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			alpha_pos = argv[1][i] - 64;
			alpha_count = 0; 
				while (alpha_count < alpha_pos)
				{
					ft_putchar(argv[1][i]);
					alpha_count++;
				}
				i++;
		}
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
                {
                        alpha_pos = argv[1][i] - 96;
			alpha_count = 0;
                                while (alpha_count < alpha_pos)
                                {
                                        ft_putchar(argv[1][i]);
                                        alpha_count++;
                                }
				i++;
                }
	}
	ft_putchar('\n');
}
