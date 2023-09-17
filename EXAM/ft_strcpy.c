char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	while (s1[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

#include <stdio.h>

int	main(void)
{
	char	a[100] = "Oui";
	char	b[] = "Non";

	printf("%s", ft_strcpy(a, b));
	return (0);
}
