#include <stdlib.h>
#include <stdio.h>

int		ft_iterative_power(int nb, int power)
{
	int		c;

	c = 1;
	if (power > 0)
	{
		while (power > 0)
		{
			c = c * nb;
			--power;
		}
		return (c);
	}
	else if (power == 0)
		return (1);
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
		printf("%i to the power %i\n%i\n", atoi(argv[1]), atoi(argv[2]), ft_iterative_power(atoi(argv[1]), atoi(argv[2])));
	return(0);
}
