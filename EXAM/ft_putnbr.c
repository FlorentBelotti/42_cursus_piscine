void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb = -2147483648)
		write (1, "-2147483647", 11);
	if (nb < 0)
	{
		nb = -nb;
		write (1, "-", 1);
	}
	while (nb > 9)
	{
		ft_putnbr(nb / 10); 
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
}
