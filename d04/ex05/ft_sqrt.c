#include <stdio.h>
#include <stdlib.h>

	// Iterative Methode:

int		ft_sqrt(int nb)		//could obviously be done iteratively by checking every number with a few clauses to speed up, but rather long winded
{
	int		i;

	i = 2;
	if (nb == 1 || nb == 4)			// use == 4 here to get rid of = in <= of while
		return (nb);
	while (i < nb / 2)
	{
		if (i * i == nb)
			return (i);
		else
			++i;
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%i\n%i\n", atoi(argv[1]), ft_sqrt(atoi(argv[1])));
	return (0);
}
