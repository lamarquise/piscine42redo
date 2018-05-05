#include <unistd.h>
#include <stdlib.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)					//had just >, that makes last (first) digit not be printed when equal to a power of 10
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}

int		main(int argc, char *argv[])
{
	int		a;

	a = atoi(argv[1]);
	if (argc == 1)
		return (0);
	else if (argc == 2)
		ft_putnbr(a);
	return (0);
}
