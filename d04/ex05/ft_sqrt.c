#include <stdio.h>
#include <stdlib.h>

int		ft_sqrt(int nb)		//could obviously be done iteratively by checking every number with a few clauses to speed up, but rather long winded
{
	if (nb > 0)
		return 
	return (0);				//work on this later, would be nice to do it interestingly
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%i\n%i\n", atoi(argv[1]), ft_sqrt(atoi(argv[1])));
	return (0);
}
