#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		base_check(char *base, int *l)		//this function is a bit longer than it needs to be but it's clear so im good with that
{
	int		c;

	*l = 0;									//fairly certain this is the bit i forgot and reason it was segfaulting for the longest time
	while (base[*l])
	{
		c = 0;
		while (base[c])
		{
			if (base[c] == base[*l] && *l != c)
				return (0);
			++c;
		}
		if (base[*l] == '+' || base[*l] == '-')
			return (0);
		++*l;
	}
	if (*l <= 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nb, char *base)		//would it be faster if iterative? perhaps not by enough to be worth it
{
	long	nbr;
	int		l;

	nbr = nb;
	if (base_check(base, &l) == 1)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		if (nbr >= l)
			ft_putnbr_base(nbr / l, base);
		ft_putchar(base[nbr % l]);
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
		ft_putnbr_base(atoi(argv[1]), argv[2]);
	return (0);
}
