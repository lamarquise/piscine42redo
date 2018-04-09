#include <stdio.h>
#include <stdlib.h>

int		ft_recursive_factorial(int nb)
{
	if (nb <= 13 && nb > 0)
		return (nb * ft_recursive_factorial(nb - 1));
	else if (nb == 0)
		return (1);
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%i\n%i\n", atoi(argv[1]), ft_recursive_factorial(atoi(argv[1])));
	return (0);
}
