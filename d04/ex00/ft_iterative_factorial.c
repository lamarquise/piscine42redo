#include <stdio.h>
#include <stdlib.h>

int		ft_iterative_factorial(int nb)
{
	int		c;

	c = nb;
	if (nb <= 13 && nb > 0)
	{
		while (nb > 1)
		{
			c = c * (nb - 1);
			--nb;
		}
		return (c);
	}
	else if (nb == 0)
		return (1);
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%i\n%i\n", atoi(argv[1]), ft_iterative_factorial(atoi(argv[1])));
	return (0);
}
