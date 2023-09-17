/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:34:55 by fbelotti          #+#    #+#             */
/*   Updated: 2023/09/14 19:06:21 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i); 
}

char	*ft_strrev(char *str)
{
	char	temp;
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		i++;
	}
	return (str);
}

#include <stdio.h>

int main(void)
{
    char str[] = "hello";
    printf("Original string: %s\n", str);

    ft_strrev(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
