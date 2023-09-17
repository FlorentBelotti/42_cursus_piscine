int strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char *strcpy(char *src, char *dest)
{
	int	i; 

	i = 0;
	while (src[i])
	{
		dest[i] = src[i]
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_strdup(char *src)
{
	char *dest;

	dest = (char *) malloc (sizeof(char) * ft_strlen(src) + 1); 
	if (dest == 0)
		return (NULL);
	else
		strcpy(src, dest);
	return (dest);
}	
