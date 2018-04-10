#include <stdio.h>
#include <stdlib.h>

int		ft_recursive_power(int nb, int power)
{
	if (power > 0)
		return (nb * ft_recursive_power(nb, power - 1));
	else if (power == 0)
		return (1);					//If you were to return 0 here, you would always end up with 0, if 2, you would get double your result
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
		printf("%i to the power %i\n%i\n", atoi(argv[1]), atoi(argv[2]), ft_recursive_power(atoi(argv[1]), atoi(argv[2])));
	return (0);
}
