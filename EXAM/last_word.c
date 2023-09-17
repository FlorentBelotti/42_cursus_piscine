int	main(int argc, char **argv)
{
	int	i;
	int	temp;

	while (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 126 && argv[1][i] <= 126 && argv[1][i-1] == ' ')
