/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:40:53 by fbelotti          #+#    #+#             */
/*   Updated: 2023/08/28 16:12:05 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (!((str[i] > 48 && str[i] <= 57)))
			return (0);
		i++;
	}
	return (1);
}

/* int     main(void)
{
        printf("%d", ft_str_is_numeric("123"));
        return (0);
} */ 
